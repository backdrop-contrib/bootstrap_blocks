<div style="
     <?php if (($hero_padding > 0)) { ?>
 padding:       <?php echo $hero_padding; ?>px; <?php } ?>
 
     <?php if (($hero_margin > 0)) { ?>
 margin:        <?php echo $hero_margin; ?>px;  <?php } ?>
     <?php if (($hero_round > 0)) { ?>
 border-radius: <?php echo $hero_round; ?>px;   <?php } ?>
">

  <div class="it-hero-wrapper <?php if ($hero_background_url) { ?>
 it-dark it-overlay <?php } ?>
 <?php if (($hero_card_title && $hero_card_content)) { ?>
 it-bottom-overlapping-content <?php } ?>
">
    <?php if ($hero_background_url) { ?>
      <div class="img-responsive-wrapper">
        <div class="img-responsive">
          <div class="img-wrapper"><img src="<?php echo $hero_background_url; ?>" title="<?php echo $hero_background_title; ?>" alt="<?php echo $hero_background_alt; ?>"></div>
        </div>
    </div>
    <?php } ?>

    <div class="container">
      <div class="row">
        <div class="col-12">
          <div class="it-hero-text-wrapper bg-dark">
            <span class="it-category"><?php echo $hero_category; ?></span>
            <h1 class="no_toc"><?php echo $hero_title; ?></h1>
            <p class="d-none d-lg-block"><?php echo $hero_content; ?></p>
            <div class="it-btn-container"><a class="btn btn-sm btn-outline-primary" href="<?php echo $hero_button_url; ?>"><?php echo $hero_button_title; ?></a></div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <?php if (($hero_card_title && $hero_card_content)) { ?>
  <div class="container">
    <div class="row">
      <div class="col-12">
        <div class="card-wrapper card-space">
          <div class="card card-bg">
            <div class="card-body">
              <h5 class="card-title"><?php echo $hero_card_title; ?></h5>
              <p class="card-text"><?php echo $hero_card_content; ?></p>
              <?php if (($hero_card_link_title && $hero_card_link_url)) { ?>
              <a class="read-more" href="<?php echo $hero_card_link_url; ?>">
                <span class="text"><?php echo $hero_card_link_title; ?></span>
                <svg class="icon">
                  <use xlink:href="./themes/custom/italiagov/assets/icons/sprite.svg#it-arrow-right"></use>
                </svg>
              </a>
              <?php } ?>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <?php } ?>
</div>