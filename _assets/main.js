jQuery(document).ready(function($){
  //open interest point description
  $('.cd-single-point').children('a').on('click', function(){
      var selectedPoint = $(this).parent('li');
      if( selectedPoint.hasClass('is-open') ) {
          selectedPoint.removeClass('is-open').addClass('visited');
      } else {
          selectedPoint.addClass('is-open').siblings('.cd-single-point').removeClass('is-open');
      }
  });
  //close interest point description
  $('.cd-close-info').on('click', function(event){
      event.preventDefault();
      $(this).parents('.cd-single-point').eq(0).removeClass('is-open').addClass('visited');
  });

  // $('body > header').particleground({
  //   dotColor: '#ffffff',
  //   lineColor: '#ffffff',
  //   maxSpeedX: 0.3,
  //   directionX: 'right',
  //   directionY: 'right'
  // });

  $.scrollIt({
    upKey: 38,             // key code to navigate to the next section
    downKey: 40,           // key code to navigate to the previous section
    easing: 'linear',      // the easing function for animation
    scrollTime: 600,       // how long (in ms) the animation takes
    activeClass: 'active', // class given to the active nav element
    onPageChange: null,    // function(pageIndex) that is called when page is changed
    topOffset: 0           // offste (in px) for fixed top navigation
  });
});
