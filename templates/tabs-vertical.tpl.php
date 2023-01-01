<div class="bd-example-tabs" style="
  <?php if (($tabs_padding > 0)) { ?>
 padding: <?php echo $tabs_padding; ?>px; <?php } ?>
 
  <?php if (($tabs_margin > 0)) { ?>
 margin:  <?php echo $tabs_margin; ?>px;  <?php } ?>
">
  
  <div class="row">
    <div class="col-4 col-md-3">
      <ul class="nav nav-tabs nav-tabs-vertical <?php if ($tab_background) { ?>
 nav-tabs-vertical-background <?php } ?>
" id="myTab" role="tablist" aria-orientation="vertical">
        <li class="nav-item">
          <a class="nav-link <?php if ($first_tab_active) { ?>
 active <?php } else { ?>
 disabled <?php } ?>
" id="<?php echo ($tab_id . '1'); ?>-tab" data-toggle="tab" href="#<?php echo ($tab_id . '1'); ?>" role="tab" aria-controls="<?php echo ($tab_id . '1'); ?>" aria-selected="<?php if ($first_tab_active) { ?>
 true <?php } else { ?>
 false <?php } ?>
">
            <?php echo $first_tab_title; ?>
            <?php if ($first_tab_icon) { ?>
              <svg class="icon icon-primary">
                <use xlink:href="./themes/custom/italiagov/assets/icons/sprite.svg#<?php echo $first_tab_icon; ?>"></use>
              </svg>
            <?php } ?>
          </a>
        </li>

        <li class="nav-item">
          <a class="nav-link <?php if (($second_tab_active &&  !$first_tab_active)) { ?>
 active <?php } elseif ( !$second_tab_active) { ?>
 disabled <?php } ?>
" id="<?php echo ($tab_id . '2'); ?>-tab" data-toggle="tab" href="#<?php echo ($tab_id . '2'); ?>" role="tab" aria-controls="<?php echo ($tab_id . '1'); ?>" aria-selected="<?php if (($second_tab_active &&  !$first_tab_active)) { ?>
 true <?php } else { ?>
 false <?php } ?>
">
            <?php echo $second_tab_title; ?>
            <?php if ($second_tab_icon) { ?>
              <svg class="icon icon-primary">
                <use xlink:href="./themes/custom/italiagov/assets/icons/sprite.svg#<?php echo $second_tab_icon; ?>"></use>
              </svg>
            <?php } ?>
          </a>
        </li>
        
        <li class="nav-item">
          <a class="nav-link <?php if (($third_tab_active && ( !$second_tab_active &&  !$first_tab_active))) { ?>
 active <?php } elseif ( !$third_tab_active) { ?>
 disabled <?php } ?>
" id="<?php echo ($tab_id . '3'); ?>-tab" data-toggle="tab" href="#<?php echo ($tab_id . '3'); ?>" role="tab" aria-controls="<?php echo ($tab_id . '3'); ?>" aria-selected="<?php if (($third_tab_active && ( !$second_tab_active &&  !$first_tab_active))) { ?>
 true <?php } else { ?>
 false <?php } ?>
">
            <?php echo $third_tab_title; ?>
            <?php if ($third_tab_icon) { ?>
              <svg class="icon icon-primary">
                <use xlink:href="./themes/custom/italiagov/assets/icons/sprite.svg#<?php echo $third_tab_icon; ?>"></use>
              </svg>
            <?php } ?>
          </a>
        </li>
      </ul>
    </div>

    <div class="col-8 col-md-9">
      <div class="tab-content" id="myTabContent">
        <div class="tab-pane p-4 fade <?php if ($first_tab_active) { ?>
 show active <?php } ?>
" id="<?php echo ($tab_id . '1'); ?>" role="tabpanel" aria-labelledby="<?php echo ($tab_id . '1'); ?>-tab"><?php echo $first_tab_content; ?></div>
        <div class="tab-pane p-4 fade <?php if (($second_tab_active &&  !$first_tab_active)) { ?>
 show active <?php } ?>
" id="<?php echo ($tab_id . '2'); ?>" role="tabpanel" aria-labelledby="<?php echo ($tab_id . '2'); ?>-tab"><?php echo $second_tab_content; ?></div>
        <div class="tab-pane p-4 fade <?php if (($third_tab_active && ( !$second_tab_active &&  !$first_tab_active))) { ?>
 show active <?php } ?>
" id="<?php echo ($tab_id . '3'); ?>" role="tabpanel" aria-labelledby="<?php echo ($tab_id . '3'); ?>-tab"><?php echo $third_tab_content; ?></div>
      </div>
    </div>
  </div>
</div>