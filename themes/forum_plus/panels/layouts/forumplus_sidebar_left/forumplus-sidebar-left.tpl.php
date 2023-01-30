<div
  class="panel-display boxton clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>"
  <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <section id="content-main-wrapper" class="content-main sidebar-first-wrapper">
    <div class="container">
      <div class="row">
        <?php if (!empty($content['content_sidebar_first'])): ?>
        <aside class="sidebar sidebar-first col col-12 col-md-3 mt-0 order-last">
          <?php print $content['content_sidebar_first']; ?>
        </aside>
        <?php endif; ?>
        <?php if (!empty($content['content_main'])): ?>
        <div class="main-inner col-md-9 pr-0">
          <?php print $content['content_main']; ?>
        </div>
        <?php endif; ?>
      </div>
    </div>
  </section>
</div>