<div style="
  <?php if (($tabs_padding > 0)) { ?>
 padding: <?php echo $tabs_padding; ?>px; <?php } ?>
  
 
  <?php if (($tabs_margin > 0)) { ?>
 margin:  <?php echo $tabs_margin; ?>px;  <?php } ?>
">
  
  <ul class="nav nav-tabs" id="myTab" role="tablist">
  <?php foreach ($tabs as $delta => $item): ?>
    <?php $active = ($delta == 0) ? 'active' : ''; ?>
    <li class="nav-item">
      <button class="nav-link <?php echo $active; ?>" id="tab-<?php echo $delta; ?>" data-bs-toggle="tab" data-bs-target="#tab-content-<?php echo $delta; ?>" role="tab" type="button" aria-controls="tab-content-<?php echo $delta; ?>" aria-selected="true">
      <?php echo $item['title']; ?>
      </button>
    </li>
    <?php endforeach; ?>
  </ul>

  <div class="tab-content" id="myTabContent">
  <?php foreach ($tabs as $delta => $item): ?>
    <?php $active = ($delta == 0) ? 'show active' : ''; ?>
    <div class="tab-pane p-4 fade <?php echo $active; ?>" id="tab-content-<?php echo $delta; ?>" role="tabpanel" aria-labelledby="tab-content-<?php echo $delta; ?>-tab"><?php echo $item['content']; ?></div>
    <?php endforeach; ?>
  </div>
</div>

