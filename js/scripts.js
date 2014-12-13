$(document).ready(function () {
    var browserDetect = function() {
        var el = document.getElementsByTagName('body')[0],
        wn = window.navigator,
        platform = wn.platform.toString().toLowerCase(),
        userAgent = wn.userAgent.toLowerCase(),
        versionRegex,
        storedName,
        combinedClasses,
        browserOsVersion,
        browserName,
        version,
        vendor,
        os;
        // firefox
        if (userAgent.indexOf('firefox',0) !== -1) {
            versionRegex = /firefox\/\d\d?\.\d/;
            browserName = 'ff';
            storedName = userAgent.match(versionRegex).toString().replace(/\./g,'');
            version = storedName.replace(/firefox\//,'');
            if((version.indexOf('1') === 0) && (version.length > 3)){ // checking if the version is 1\d.something
                version = version.substring(0,3);
            } else {
                version = version.substring(0,2);
            }
            browserOsVersion = browserName + version;
        }
        // ie
        if (userAgent.indexOf('msie',0) !== -1) {
            browserName = 'ie';
            os = 'win';
            storedName = userAgent.match(/msie[ ]\d{1}/).toString();
            version = storedName.replace(/msie[ ]/,'');
            browserOsVersion = browserName + version;
        }
        // safari and chrome
        if (userAgent.indexOf('webkit',0) !== -1) {
            browserName = 'wbk';
            vendor = wn.vendor.toLowerCase(); // not a standard property
            if(vendor.search('apple') >= 0){
                browserName = 'sfr';
                versionRegex = /version\/\d[.]\d/;
                storedName = userAgent.match(versionRegex).toString();
                version = storedName.replace(/version\//,'').replace('.','');
            } else if(vendor.search('google') >= 0) {
                browserName = 'crm';
                versionRegex = /chrome\/\d\d?\.\d?/;
                storedName = userAgent.match(versionRegex).toString().replace('.','');
                version = storedName.replace(/chrome\//,'').substring(0,3);
            }
            browserOsVersion = browserName + version;
        }
        // os
        if (!os) {
            if (platform.search('win') >= 0) {
                os = 'win';
            }
            if (platform.search('mac') >= 0) {
                os = 'mac';
            }
            if (userAgent.search('iphone') >= 0){
                os = 'idevice';
            }
            if (platform.search('linux') >= 0) {
                os = 'lin';
            }
        }

        combinedClasses = os + ' ' + browserName + ' ' + browserOsVersion;
        if(el.className){
            combinedClasses += ' ' + el.className;
        }

        return os;
    };

    os = browserDetect();

    mac_release = "https://github.com/knossos-project/knossos/releases/download/v4.0.1/mac-Knossos.4.0.1.zip";
    linux_release = "https://github.com/knossos-project/knossos/releases/download/v4.0.1/knossos.deb";

    if(os == "mac") {
        $(".download-btn").attr("href", mac_release);
        $(".download-icon").attr("class", "fa fa-apple fa-fw");
    }

    if(os == "linux") {
        $(".download-btn").attr("href", linux_release);
        $(".download-icon").attr("class", "fa fa-linux fa-fw");
    }
});






// waypoints
$(document).ready(function() {

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
    $('.wp3').addClass('animated fadeInUpD');
  }, {
    offset: '75%'
  });

  $('.wp4').waypoint(function() {
    $('.wp4').addClass('animated fadeInUpD');
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