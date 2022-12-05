<?php ?>


<div class="jumbotron jumbotron-fluid">
  <header id="header" class="header section">
    <div class="container">
      <div class="row">
        <div class="col col-12 col-lg-4 text-center">
          <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Back to Home'); ?>" rel="home" id="logo">
            <img src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/logos/swaylocks-2005-white.png"
              alt="<?php print t('Back to Home'); ?>">
          </a>
          <?php endif; ?>
          <?php if ($site_name || $site_slogan): ?>
          <div id="name-and-slogan">
            <?php if ($site_name): ?>
            <?php if ($title): ?>
            <div id="site-name"><strong>
                <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"
                  rel="home"><span><?php print $site_name; ?></span></a>
              </strong></div>
            <?php else: /* Use h1 when the content title is empty */ ?>
            <h1 id="site-name">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"
                rel="home"><span><?php print $site_name; ?></span></a>
            </h1>
            <?php endif; ?>
            <?php endif; ?>

            <?php if ($site_slogan): ?>
            <div id="site-slogan"><?php print $site_slogan; ?></div>
            <?php endif; ?>
          </div>
          <?php endif; ?>
        </div>

        <div class="col col-12 col-lg-8">
          <?php print render($page['header']); ?>
        </div>
      </div>
  </header>


  <video class="video-hero-video" poster="https://swaylockslive.s3.us-east-2.amazonaws.com/public/video/spaceman.jpg"
    autoplay playsinline loop muted>
    <source src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/video/spaceman-small2.mp4"
      data-src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/video/spaceman-small2.mp4" type="video/mp4">
    Your browser does not support HTML5 video.
  </video>
</div>

<div class="container">
  <div class="row">
    <div class="col col-12 col-md-6 col-lg-4">
      <a target="_blank" href="https://discord.com/invite/fR8Eu46vt6"><img
          src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/forums-blue-1.png" /></a>
    </div>
    <div class="col col-12 col-md-6 col-lg-4">
      <a target="_blank" href="/archive"><img
          src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/the-archives-1.png" /></a>
    </div>
    <div class="col col-12 col-md-6 col-lg-4">
      <a target="_blank" href="https://www.instagram.com/swaylocksarchive/"><img
          src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/instagram-smaller.jpg" /></a>
    </div>
    <div class="col col-12 col-md-6 col-lg-4">
      <a target="_blank" href="https://swaylocks.substack.com"><img
          src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/digest-square.png" /></a>
    </div>
    <div class="col col-12 col-md-6 col-lg-4">
      <a target="_blank" href="https://www.patreon.com/swaylocks"><img
          src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/keep-swaylock-alive-2.png" /></a>
    </div>
    <div class="col col-12 col-md-6 col-lg-4"><img
        src="https://swaylockslive.s3.us-east-2.amazonaws.com/public/build-of-the-month-2.png" />
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