<div class="row">
  <div class="col-12 col-lg-6">
    <div class="card-wrapper card-space">
      <div class="card card-bg" 
           style="
           <?php if (($card_padding > 0)) { ?>
 padding:       <?php echo $card_padding; ?>px; <?php } ?>
 
           <?php if (($card_margin > 0)) { ?>
 margin:        <?php echo $card_margin; ?>px;  <?php } ?>
           <?php if (($card_round > 0)) { ?>
 border-radius: <?php echo $card_round; ?>px;   <?php } ?>
">
        <div class="card-body">
          <h5 class="card-title"><?php echo $first_card_title; ?></h5>
          <p class="card-text"><?php echo $first_card_content; ?></p>
          <a class="read-more" href="<?php echo $first_card_link_url; ?>">
            <span class="text"><?php echo $first_card_link_title; ?></span>
            <svg class="icon">
              <use xlink:href="./themes/custom/italiagov/assets/icons/sprite.svg#it-arrow-right"></use>
            </svg>
          </a>
        </div>
      </div>
    </div>
  </div>

  <div class="col-12 col-lg-6">
    <div class="card-wrapper card-space">
      <div class="card card-bg" 
           style="
           <?php if (($card_padding > 0)) { ?>
 padding:       <?php echo $card_padding; ?>px; <?php } ?>
 
           <?php if (($card_margin > 0)) { ?>
 margin:        <?php echo $card_margin; ?>px;  <?php } ?>
           <?php if (($card_round > 0)) { ?>
 border-radius: <?php echo $card_round; ?>px;   <?php } ?>
">
        <div class="card-body">
          <h5 class="card-title"><?php echo $second_card_title; ?></h5>
          <p class="card-text"><?php echo $second_card_content; ?></p>
          <a class="read-more" href="<?php echo $second_card_link_url; ?>">
            <span class="text"><?php echo $second_card_link_title; ?></span>
            <svg class="icon">
              <use xlink:href="./themes/custom/italiagov/assets/icons/sprite.svg#it-arrow-right"></use>
            </svg>
          </a>
        </div>
      </div>
    </div>
  </div>
</div>