window._skel_config = {
    prefix: "css/style",
    preloadStyleSheets: true,
    resetCSS: true,
    boxModel: "border",

    breakpoints: {
      global:		{ range: '*', containers: 1400, grid: { gutters: 50 } },
		  wide:		{ range: '-1680', containers: 1200, grid: { gutters: 40 } },
		  normal:		{ range: '-1280', containers: 960, lockViewport: true },
		  narrow:		{ range: '-980', containers: '95%', grid: { gutters: 30 } },
		  narrower:	{ range: '-840', grid: { collapse: 1 } },
		  mobile:		{ range: '-640', containers: '100%', grid: { gutters: 15, collapse: 2 } }
	  }
};

window._skel_panels_config = {


  panels: {
		leftPanel: {
			breakpoints: 'narrower,mobile',
			position: 'left',
			size: 250,
			html: '<div data-action="moveCell" data-args="left-sidebar,content"></div>'
		},
		rightPanel: {
			breakpoints: 'narrower,mobile',
			position: 'right',
			size: 250,
			html: '<div data-action="moveCell" data-args="right-sidebar,content"></div>'
		},
		bottomPanel: {
			position: 'bottom',
			size: 420
			/*
				Since this panel is a bit more complicated, we're omitting its 'html' option and
				defining it inline (ie. in index.html).
			*/
		}
	},
	overlays: {
		titleBar: {
			breakpoints: 'mobile',
			position: 'top-center',
			width: '100%',
			height: 44,
			html: '<div data-action="copyHTML" data-args="title"></div>'
		},
		contactBar: {
			position: 'bottom-center',
			width: 250,
			height: 60,
			html:	'<a href="http://twitter.com/n33co" class="icon-twitter"></a>' +
					'<a href="#" class="toggle icon-envelope" data-action="togglePanel" data-args="bottomPanel"></a>' +
					'<a href="http://twitter.com/n33co" class="icon-facebook"></a>'
		},
		leftPanelButton: {
			breakpoints: 'narrower,mobile',
			position: 'top-left',
			width: 80,
			height: 60,
			html: '<div class="toggle icon-angle-right" data-action="togglePanel" data-args="leftPanel"></div>'
		},
		rightPanelButton: {
			breakpoints: 'narrower,mobile',
			position: 'top-right',
			width: 80,
			height: 60,
			html: '<div class="toggle icon-angle-left" data-action="togglePanel" data-args="rightPanel"></div>'
		}
	}
};


(function($) {

	/* scrolly v0.1 | (c) n33 | n33.co @n33co | MIT */
		(function(e){var t="click.scrolly";e.fn.scrolly=function(r,i){r||(r=1e3),i||(i=0),e(this).off(t).on(t,function(t){var n,s,o,u=e(this),a=u.attr("href");a.charAt(0)=="#"&&a.length>1&&(n=e(a)).length>0&&(s=n.offset().top,u.hasClass("scrolly-centered")?o=s-(e(window).height()-n.outerHeight())/2:(o=Math.max(s,0),i&&(typeof i=="function"?o-=i():o-=i)),t.preventDefault(),e("body,html").stop().animate({scrollTop:o},r,"swing"))})}})(jQuery);

	$(function() {

		var $body = $('body'),
			$window = $(window),
			$header = $('#header'),
			$banner = $('#banner');

		// Re-enable animations until we're done loading everything.
			$window.load(function() {
				$body.removeClass('loading');
			});

		// Scrolly links.
			$('.scrolly').scrolly(1000, -10);

		// Dropdowns.
			$('#nav > ul').dropotron({
				offsetY: -13,
				mode: 'fade',
				noOpenerFade: true,
				expandMode: (skel.vars.isTouch ? 'click' : 'hover')
			});

		// Header.
		// If the header is using "alt" styling and #banner is present, use scrollwatch
		// to revert it back to normal styling once the user scrolls past the banner.
		// Note: This is disabled on touch devices and whenever the 'normal' breakpoint is
		// active (effectively disabling it on 'narrow', 'narrower', and 'mobile' as well).
			if ($header.hasClass('alt')
			&&	$banner.length > 0) {

				$window.on('load', function() {

					// scrollgress v0.2 | (c) n33 | n33.co @n33co | MIT
						(function(){var e="scrollwatch",t="length",n="top",r=null,i="scrollgress",s="data",o="scrollwatch-state",u="range",a="anchor",f="unscrollwatch",l="unscrollgress",c="removeData",h="element",p="-id",d="scroll.",v="height",m="scrollTop",g="center",y="bottom",b=$(window),w=$(document),E=1e3;$.fn[e]=function(f){var l,c,h,p;if(this[t]>1){for(l=0;l<this[t];l++)$(this[l])[e](f);return this}return c=$.extend({range:.5,anchor:n,init:r,on:r,off:r,delay:0},f),h=$(this),c.init&&c.init(h),h[s](o,-1)[i](function(e){window.clearTimeout(p),p=window.setTimeout(function(){var t=parseInt(h[s](o));if(t==0||t==-1)if(e>=-1*c[u]&&e<=c[u]){h[s](o,1),c.on&&c.on(h);return}if(t==1||t==-1)if(e<-1*c[u]||e>=c[u]){h[s](o,0),c.off&&c.off(h);return}},c.delay)},{anchor:c[a]},e),h},$.fn[f]=function(){var n,r;if(this[t]>1){for(n=0;n<this[t];n++)$(this[n])[f]();return this}return r=$(this),r[c](o,0)[l](e),r},$.fn[i]=function(e,r,o){var u,f,l,c,S;if(this[t]>1){for(u=0;u<this[t];u++)$(this[u])[i](e,r,o);return this}return o||(o=i),f=$.extend({anchor:n,direction:"both",scope:h,easing:0},r),l=$(this),l[s](o+p)||l[s](o+p,E++),c=l[s](o+p),S=d+o+"-"+c,b.off(S).on(S,function(){var t,r=l.offset()[n],i=l.outerHeight(),s=w[v]();switch(f.scope){default:case h:switch(f[a]){default:case n:t=(r-b[m]())/i*-1;break;case g:t=(r-b[m]()-(b[v]()-i)/2)/i*-1;break;case y:t=(r-b[m]()-(b[v]()-i))/i*-1}break;case"window":switch(f[a]){default:case n:t=(r-b[m]())/b[v]()*-1;break;case g:t=(r-b[m]()-(b[v]()-i)/2)/b[v]()*-1;break;case y:t=(r-b[m]()-(b[v]()-i))/b[v]()*-1}}f.direction=="forwards"?t=Math.max(0,t):f.direction=="backwards"&&(t=Math.min(0,t)),t>0?t=Math.max(0,t-f.easing/100):t<0&&(t=Math.min(0,t+f.easing/100)),e(t,l)}).trigger("scroll"),l},$.fn[l]=function(e){var n,r,o,u;if(this[t]>1){for(n=0;n<this[t];n++)$(this[n])[l](e);return this}return e||(e=i),r=$(this),r[s](e+p)?(o=r[s](e+p),u=d+e+"-"+o,b.off(u),r[c](e+p),r):r}})();

					// Apply scrollgress to banner.
						$banner.scrollwatch({
							delay:		0,
							range:		1,
							anchor:		'top',
							on:			function() { $header.addClass('alt reveal'); },
							off:		function() { $header.removeClass('alt'); }
						});

				});

			}

	});

})(jQuery);
