<?php ?>


<div class="jumbotron">
  <header id="header" class="header section">
    <div class="container">
      <div class="row">
        <div class="col col-12 text-center">
          <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Back to Home'); ?>" rel="home" id="logo">
            <img src="https://swaylockslive.s3.amazonaws.com/public/logos/swaylocks-2005-black-400-trans.png"
              alt="<?php print t('Back to Home'); ?>">
          </a>
          <?php endif; ?>
        </div>
      </div>
  </header>
  <video class="video-hero-video" poster="https://swaylockslive.s3.us-east-2.amazonaws.com/public/video/spaceman.jpg"
    autoplay playsinline loop muted>
    <source src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/video/spaceman-small2.mp4"
      data-src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/video/spaceman-small2.mp4" type="video/mp4">
    Your browser does not support HTML5 video.
  </video>
  <div class="container">
    <div class="slogan d-flex align-items-center text-center">
      <h1>A community for surfboard lovers &amp; the people that make them</h1>
    </div>
  </div>
</div>

<div class="container pb-4">
  <div class="row m-0 mb-4 pb-1 pt-1" style="background-color: lightgray; border-radius: 5px;">
    <div class="col col-12 pl-1 pr-1">
      <div class="google_search">
        <section id="google_search" class="section">
          <script async src="https://cse.google.com/cse.js?cx=003250312232961279926:i8tfrcq3eyy">
          </script>
          <div class="gcse-search"></div>
        </section>
      </div>
    </div>
  </div>
  <div class="row">
    <div class="col col-12 col-md-6 col-lg-4 mb-4">
      <a target="_blank" href="https://discord.com/invite/fR8Eu46vt6"><img
          src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/forums-blue-1.png" /></a>
    </div>
    <div class="col col-12 col-md-6 col-lg-4 mb-4">
      <a target="_blank" href="https://swaylocks.substack.com"><img
          src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/digest-square.png" /></a>
    </div>
    <div class="col col-12 col-md-6 col-lg-4 mb-4">
      <a target="_blank" href="https://swaylocks.substack.com/p/enter-to-win-new-build-of-the-month"><img
          src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/build-of-the-month-12.png" /></a>
    </div>
    <div class="col col-12 col-md-6 col-lg-4 mb-4">
      <a target="_blank" href="/archive"><img
          src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/the-archives-1.png" /></a>
    </div>
    <div class="col col-12 col-md-6 col-lg-4 mb-4">
      <a target="_blank" href="https://www.instagram.com/swaylocksarchive/"><img
          src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/instagram-smaller.jpg" /></a>
    </div>
    <div class="col col-12 col-md-6 col-lg-4 mb-4">
      <a target="_blank" href="https://ko-fi.com/swaylocks"><img
          src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/keep-swaylock-alive-2.png" /></a>
    </div>

  </div>
</div>
<?php if($footer = render($page['footer'])): ?>
<footer id="footer" class="section">
  <div class="container">
    <?php print $footer; ?>
    <!--?php print $feed_icons; ?-->
  </div>
</footer>
<?php endif;?>

<a title="<?php print t('Back to Top')?>" class="btn-btt" href="#Top" style="display: none;"><?php print t('Top')?></a>