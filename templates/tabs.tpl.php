<?php $tabs_padding = ($tabs_padding > 0) ? 'padding: ' . $tabs_padding . 'px': ''; ?>
<?php $tabs_margin = ($tabs_margin > 0) ? 'margin: ' . $tabs_margin . 'px' : ''; ?>
<?php if ($v_tabs) {
    $v_tabs_align = 'class="d-flex align-items-start"';
    $v_tabs_column = 'flex-column';
  }
  else {
    $v_tabs_align = '';
    $v_tabs_column = '';
  }
  ?>

<div style="<?php echo $tabs_padding; ?> <?php echo $tabs_margin; ?>" <?php echo $v_tabs_align; ?>>
  
  <div class="nav nav-pills <?php echo $v_tabs_column; ?>" id="myTab" role="tablist">
  <?php foreach ($tabs as $delta => $item): ?>
    <?php $active = ($delta == 0) ? 'active' : ''; ?>
      <button class="nav-link <?php echo $active; ?>" id="tab-<?php echo $delta; ?>" data-bs-toggle="tab" data-bs-target="#tab-content-<?php echo $delta; ?>" role="tab" type="button" aria-controls="tab-content-<?php echo $delta; ?>" aria-selected="true">
      <?php echo $item['title']; ?>
      </button>
    <?php endforeach; ?>
  </div>

  <div class="tab-content" id="myTabContent">
  <?php foreach ($tabs as $delta => $item): ?>
    <?php $active = ($delta == 0) ? 'show active' : ''; ?>
    <div class="tab-pane p-4 fade <?php echo $active; ?>" id="tab-content-<?php echo $delta; ?>" role="tabpanel" aria-labelledby="tab-content-<?php echo $delta; ?>-tab"><?php echo $item['content']; ?></div>
    <?php endforeach; ?>
  </div>
</div>

