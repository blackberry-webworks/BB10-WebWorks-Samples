function initApp() {
	// fade in the button to connect after webworks sdk has loaded
	$('#setupBBM').fadeIn();
}

function setupBBM () {
  //Register the app and push the update profile page.
	var settings = { uuid: "9862cc20-c06f-11e1-afa7-0800200c9a66" };
    blackberry.event.addEventListener("onaccesschanged", changedCallback);
    blackberry.bbm.platform.register(settings);
	bb.pushScreen('bbm.html', 'bbm');
}

function changedCallback(allowed, reason) {
    if (allowed) {
        alert("access to BBM allowed: " + reason);
    }
}

function loadCurrentUser() {
	// select box for status
	if (blackberry.bbm.platform.self.status === 'available') {
		document.getElementById('dropdownStatus').setSelectedItem(0); //Parameter is the index of the item in the list
	}  else if (blackberry.bbm.platform.self.status === 'busy') {
  	document.getElementById('dropdownStatus').setSelectedItem(1); //Parameter is the index of the item in the list
	}
  //Set values from BBM profile
	$('#titleBar').attr("data-bb-caption","stuff");
	$('#inputPersonalMessage').val( blackberry.bbm.platform.self.personalMessage );
	$('#inputStatusMessage').val( blackberry.bbm.platform.self.statusMessage );
        blackberry.bbm.platform.self.getDisplayPicture(function (img) {
        document.getElementById("displayPicture").src = "data:;base64," + img; });
        }
function updateDisplayPicture(elm) {
  //Change display picture to users choice.
  var source = "/accounts/1000/shared/camera/"+ $('#picture').val().split('/').pop().split('\\').pop(); //Only gets file name. So choice restricted to /camera/ folder
  blackberry.bbm.platform.self.setDisplayPicture (source);
}

function inviteToDownload() {
	blackberry.bbm.platform.users.inviteToDownload()
}
function saveChanges () {
	// get status
	blackberry.bbm.platform.self.setPersonalMessage($('#inputPersonalMessage').val());
	blackberry.bbm.platform.self.setStatus($('#dropdownStatus').val(), $('#inputStatusMessage').val());
alert("Saved");
}