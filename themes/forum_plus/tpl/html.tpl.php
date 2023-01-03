<!DOCTYPE html>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <?php print $head; ?>
  <title><?php 
  if ($is_front) {
    print "Swaylock's Surfboard Design Forum";
  } else {
    print $head_title;
  }
 ?></title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">
  <meta name="HandheldFriendly" content="true">
  <meta name="apple-touch-fullscreen" content="YES">
  <?php print $styles; ?>
  <script>
  (function(ac) {
    var d = document,
      s = 'script',
      id = 'adplugg-adjs';
    var js, fjs = d.getElementsByTagName(s)[0];
    if (d.getElementById(id)) return;
    js = d.createElement(s);
    js.id = id;
    js.async = 1;
    js.src = '//www.adplugg.com/serve/' + ac + '/js/1.1/ad.js';
    fjs.parentNode.insertBefore(js, fjs);
  }('A48222208'));
  </script>
  <?php print $scripts; ?>
</head>

<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>

</html>