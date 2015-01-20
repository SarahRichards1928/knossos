$(document).ready(function () {
    mac_release = "https://github.com/knossos-project/knossos/releases/download/v4.0.1/mac-Knossos.4.0.1.zip";
    linux_release = "https://github.com/knossos-project/knossos/releases/download/v4.0.1/knossos.deb";

    if(navigator.userAgent.indexOf("Macintosh") > -1) {
        $(".download-btn").attr("href", mac_release);
        $(".download-icon").attr("class", "fa fa-apple fa-fw");
    }

    if(navigator.userAgent.indexOf("Linux") > -1) {
        $(".download-btn").attr("href", linux_release);
        $(".download-icon").attr("class", "fa fa-linux fa-fw");
    }
});

// waypoints
$(document).ready(function() {
    if($('.wp0').height() < 900 && $('.wp0').width() > 640) {
        wph = $('.wp0').height();
        imgh = $('.app-img').height()

        $('.hero').css('height', wph-$('.app-img').position()["top"]+wph+imgh);
    }

    $('.wp1').waypoint(function() {
        $('.wp1').addClass('animated fadeInUp');
        }, {
            offset: '75%'
    });

    $('.wp2').waypoint(function() {
        $('.wp2').addClass('animated fadeInUp');
        }, {
            offset: '75%'
    });

    $('.wp3').waypoint(function() {
        $('.wp3').addClass('animated fadeInUp');
        }, {
            offset: '75%'
    });
});


// smooth scroll
$(function() {
  $('a[href*=#]:not([href=#])').click(function() {
    if (location.pathname.replace(/^\//, '') === this.pathname.replace(/^\//, '') && location.hostname === this.hostname) {

      var target = $(this.hash);
      target = target.length ? target : $('[name=' + this.hash.slice(1) + ']');
      if (target.length) {
        $('html,body').animate({
          scrollTop: target.offset().top
        }, 2000);
        return false;
      }
    }
  });
});