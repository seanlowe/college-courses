class Skateboard:
    def __init__(self):
        self.moving = False
        self.greased = False
        #print("Skateboard's all put together.")
    
    def isMoving(self):
        if (self.moving == False):
            #print("You're not moving.")
            return False
        elif (self.moving == True):
            #print("You are in motion.")
            return True

    def isGreased(self):
        if (self.greased == False):
            #print("The bearings feel a little dry.")
            return False
        elif (self.greased == True):
            #print("The bearings are greased.")
            return True
    
    def grease(self):
        self.greased = True
        #print("A little grease never hurt anyone.")

    def kickOff(self):
        if (self.isGreased()):
            self.moving = True
            #print("You're hurtling down the sidewalk.")
        else:
            #print("Wheels must be greased before board can be ridden.")
            raise ValueError("Wheels must be greased before board can be ridden.")

    def tailGrind(self):
        if (self.isMoving()):
            self.moving = False
            #print("You slam the tail into the ground and grind to a halt.")
        else:
            #print("You must be moving to perform a tail grind.")
            raise ValueError("You must be moving to perform a tail grind.")

    
