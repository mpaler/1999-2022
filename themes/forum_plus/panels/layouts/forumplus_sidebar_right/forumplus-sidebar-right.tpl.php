<div
  class="panel-display boxton clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>"
  <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <section id="content-main-wrapper" class="content-main sidebar-second-wrapper">
    <div class="container p-0 pr-3">
      <div class="row">
        <?php if (!empty($content['content_main'])): ?>
        <div class="main-inner col-md-9">
          <?php print $content['content_main']; ?>
        </div>
        <?php endif; ?>
        <?php if(!empty($content['content_sidebar_second'])): ?>
        <aside class="sidebar sidebar-second col col-12 col-md-3 mt-0">
          <?php print $content['content_sidebar_second']; ?>
        </aside>
        <?php endif; ?>
      </div>
    </div>
  </section>
</div>