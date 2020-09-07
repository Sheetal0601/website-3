/*!
 * Custom JS for CS33
 */

// jQuery for page scrolling feature - requires jQuery Easing plugin
$(function() {
    var func = function(event) {
        var $anchor = $(this);
        $("#page-title").addClass("top-nav-collapse");
        $('html, body').stop().animate({
            scrollTop: $($anchor.attr('href')).offset().top
        }, 800, 'easeInOutExpo');
        event.preventDefault();
    };
    $('a.page-scroll').bind('click', func);
});

// Closes the Responsive Menu on Menu Item Click
$('.navbar-collapse ul li a').click(function() {
    $('.navbar-toggle:visible').click();
});

// Adds background class on scroll
$(window).scroll(function() {
    if ($(".navbar").offset().top > 65) {
        $(".navbar-fixed-top").addClass("top-nav-collapse");
    } else {
        $(".navbar-fixed-top").removeClass("top-nav-collapse");
    }
});

//TA pictures: onhover change to character pictures
$(".ta div").each(
    function() {
        var taId = this.id;
        $("#hidden-imgs").prepend($("<img>",{src:"img/people/" + taId + ".jpg"}));
        this.style.backgroundImage = "url(\"img/characters/" + taId + ".jpg\")";
	this.style.backgroundSize = "contain";
	this.style.backgroundRepeat = "no-repeat";
	this.style.backgroundPosition = "center";
        $(".ta div#" + taId).hover(
            function() {
                this.style.backgroundImage = "url(\"img/people/" + taId + ".jpg\")";
            },
            function() {
                this.style.backgroundImage = "url(\"img/characters/" + taId + ".jpg\")";
            }
        );
    }
);

function collapse(ele) {
    let content = $(ele);
    if (content.css('display') !== 'none') {
        content.css('display', 'none');
    } else {
        content.css('display', 'block');
    }
}

if ($("button.foldable").length > 0) {
    $('.foldable').click(function (event) {
        collapse(event.target.nextElementSibling);
    });
}

function changeImg(){
            const fileName = getFileName(document.getElementById("home-img").src);
            if (fileName == "TraderTomsCsFaded.png") {
              document.getElementById("home-img").src = "img/cauliflower-gnocci-no-bg";
            } else if (fileName == "cauliflower-gnocci-no-bg") {
              document.getElementById("home-img").src = "img/everything-bag-seas-no-bg";
            } else if (fileName == "everything-bag-seas-no-bg") {
              document.getElementById("home-img").src = "img/Pb-Cups-No-Bg";
            } else if (fileName == "Pb-Cups-No-Bg") {
              document.getElementById("home-img").src = "img/tt-watermelon-spread-resize.png";
            } else if (fileName == "tt-watermelon-spread-resize.png") {
              document.getElementById("home-img").src = "img/TraderTomsCsFaded.png";
            } else if (fileName == "Asset_4.svg") {
              document.getElementById("home-img").src = "static/img/shrek.png";
            } else if (fileName == "shrek.png") {
              document.getElementById("home-img").src = "static/img/Asset_7.svg";
            }

}

function getFileName(path) {
    const arr = path.split("/");
    return arr[arr.length - 1];
}

// var slideIndex = 0;
// carousel();
//
// function carousel() {
//   var i;
//   var x = document.getElementsByClassName("mySlides");
//   for (i = 0; i < x.length; i++) {
//     x[i].style.display = "none";
//   }
//   slideIndex++;
//   if (slideIndex > x.length) {slideIndex = 1}
//   x[slideIndex-1].style.display = "inline";
//   setTimeout(carousel, 2000); // Change image every 2 seconds
// }
