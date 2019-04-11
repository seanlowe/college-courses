function toggle_visible(id) {
	/* make sure all other tags are hidden */
	let idTags = ["VGD","WPD2","OSD","UID","OOP","AdvP"];
	for (i = 0; i < idTags.length; i++) {
			hide_tags(idTags[i]);
	}
	
	/* show current tag */
	let x = document.getElementById(id);
	x.style.visibility = ((x.style.visibility != 'initial') ? 'initial' : 'hidden');
}

function hide_tags(id) {
	let y = document.getElementById(id);
	y.style.visibility = 'hidden';
}

function hide_aside(id){
	let y = document.getElementById(id);
	y.style.visibility = 'hidden';
}

function toggle_table_visibility(id) {
	let table = document.getElementById(id);
	table.style.visibility = ((table.style.visibility != 'initial') ? 'initial' : 'hidden');
}

class CourseInfo {
	/* put course id, teacher, room, course name
		campus, time, days */
}


/* test functions */
function test_on_click() {
	alert("test");
}