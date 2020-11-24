var deadline = new Date("Nov 11, 2018 23:55:00").getTime();

function update_countdown() {
    var diff = deadline - new Date().getTime();
    var elem = document.getElementById("countdown")

    if (diff < 0) {
        elem.innerHTML = "NO TIME"
        return;
    }

    var days = Math.floor(diff / (1000 * 60 * 60 * 24));
    var hrs = Math.floor((diff % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
    var min = Math.floor((diff % (1000 * 60 * 60)) / (1000 * 60));
    var sec = Math.floor((diff % (1000 * 60)) / 1000);

    elem.innerHTML = days + " days, " + hrs + "h "  + min + "m " + sec + "s ";
}

update_countdown();
var timer = setInterval(update_countdown, 1000); // update every second
