<div class="panel-display boxton clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <section id="content-main-wrapper" class="content-main">
    <div class="container">
      <?php if (!empty($content['content_main'])): ?>
        <?php print $content['content_main']; ?>
      <?php endif; ?>
    </div>
  </section>
</div>
