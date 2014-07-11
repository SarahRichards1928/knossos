/*********************************************************************************/
/* Settings                                                                      */
/*********************************************************************************/

		window._skel_config = {
				prefix: 'css/style',
				resetCSS: true,
				normalizeCSS: true,
				preloadStyleSheets: true,
				boxModel: 'border',
				useOrientation: true,
				breakpoints: {
					'widest':	{ range: '1881-', hasStyleSheet: false, containers: 1400, grid: { gutters: 40 } },
					'wide':	{ range: '1621-1880', containers: 1200, grid: { gutters: 40 } },
					'normal':	{ range: '1025-1620', containers: 960, grid: { gutters: 40 } },
					'narrow':	{ range: '800-1024', containers: 'fluid', grid: { gutters: 20 } },
					'narrower':	{ range: '-800', containers: 'fluid', grid: { gutters: 15 } },
					'mobile':	{ range: '-640', containers: 'fluid', lockViewport: true, grid: { gutters: 15, collapse: true } }
				}
	};


/*********************************************************************************/
/* Don't modify beyond this point unless you know what you're doing!             */
/*********************************************************************************/

// Initialize skelJS
	skel.init();
// jQuery functions

	// scrolly
		jQuery.fn.n33_scrolly = function() {			
			var bh = jQuery('body,html'), t = jQuery(this);

			t.click(function(e) {
				var h = jQuery(this).attr('href'), target;

				if (h.charAt(0) == '#' && h.length > 1 && (target = jQuery(h)).length > 0)
				{
					var pos = Math.max(target.offset().top, 0);
					e.preventDefault();
					bh
						.stop(true, true)
						.animate({ scrollTop: pos }, 'slow', 'swing');
				}
			});
			
			return t;
		};

	// scrollzer
		jQuery.n33_scrollzer = function(ids, userSettings) {

			var top = jQuery(window), doc = jQuery(document);
			
			top.load(function() {

				// Settings
					var settings = jQuery.extend({
						activeClassName:	'active',
						suffix:				'-link',
						pad:				50,
						firstHack:			false,
						lastHack:			false
					}, userSettings);

				// Variables
					var k, x, o, l, pos;
					var lastId, elements = [], links = jQuery();

				// Build elements array
					for (k in ids)
					{
						o = jQuery('#' + ids[k]);
						l = jQuery('#' + ids[k] + settings.suffix);
					
						if (o.length < 1
						||	l.length < 1)
							continue;
						
						x = {};
						x.link = l;
						x.object = o;
						elements[ids[k]] = x;
						links = links.add(l);
					}

				// Resize event (calculates start/end values for each element)
					var resizeTimerId, resizeFunc = function() {
						var x;
						
						for (k in elements)
						{
							x = elements[k];
							x.start = Math.ceil(x.object.offset().top) - settings.pad;
							x.end = x.start + Math.ceil(x.object.innerHeight());
						}
						
						top.trigger('scroll');
					};
					
					top.resize(function() {
						window.clearTimeout(resizeTimerId);
						resizeTimerId = window.setTimeout(resizeFunc, 250);
					});

				// Scroll event (checks to see which element is on the screen and activates its link element)
					var scrollTimerId, scrollFunc = function() {
						links.removeClass('scrollzer-locked');
					};
				
					top.scroll(function(e) {
						var i = 0, h, found = false;
						pos = top.scrollTop();

						window.clearTimeout(scrollTimerId);
						scrollTimerId = window.setTimeout(scrollFunc, 250);
						
						// Step through elements
							for (k in elements)
							{
								if (k != lastId
								&&	pos >= elements[k].start
								&&	pos <= elements[k].end)
								{
									lastId = k;
									found = true;
								}
								
								i++;
							}
							
						// If we're using lastHack ...
							if (settings.lastHack
							&&	pos + top.height() >= doc.height())
							{
								lastId = k;
								found = true;
							}
							
						// If we found one ...
							if (found
							&&	!links.hasClass('scrollzer-locked'))
							{
								links.removeClass(settings.activeClassName);
								elements[lastId].link.addClass(settings.activeClassName);
							}
					});
					
				// Initial trigger
					top.trigger('resize');

			});

		};

// Ready stuff
	jQuery(function() {

		var $window = $(window)

		// Initialize scrolly links
			jQuery('.scrolly').n33_scrolly();

		// Initialize nav
			var $nav_a = jQuery('#nav a');
			
			// Scrollyfy links
				$nav_a
					.n33_scrolly()
					.click(function(e) {

						var t = jQuery(this),
							href = t.attr('href');
						
						if (href[0] != '#')
							return;
						
						e.preventDefault();
						
						// Clear active and lock scrollzer until scrolling has stopped
							$nav_a
								.removeClass('active')
								.addClass('scrollzer-locked');
					
						// Set this link to active
							t.addClass('active');
					
					});

			// Initialize scrollzer
				var ids = [];
				
				$nav_a.each(function() {
					
					var href = jQuery(this).attr('href');
					
					if (href[0] != '#')
						return;
				
					ids.push(href.substring(1));
				
				});
				
				jQuery.n33_scrollzer(ids, { pad: 200, lastHack: true });



				var $body = $('body'),
				$window = $(window),
				$header = $('#header'),
				$banner = $('#top');

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
