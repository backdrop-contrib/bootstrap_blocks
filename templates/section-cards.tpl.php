<div 
	class="section <?php if (($section_color != 'no_color')) { ?>
 section-<?php echo $section_color; ?> <?php } ?>
" 
	style="
	<?php if (($section_padding > 0)) { ?>
 padding: <?php echo $section_padding; ?>px;     			        <?php } ?>
 
	<?php if (($section_margin > 0)) { ?>
 margin: <?php echo $section_margin; ?>px;       			        <?php } ?>
	<?php if (($section_round > 0)) { ?>
 border-radius: <?php echo $section_round; ?>px; 			        <?php } ?>
	<?php if ($section_background) { ?>
  background-image: url('<?php echo $section_background; ?>'); <?php } ?>
	<?php if ($section_text_color) { ?>
  color: <?php echo $section_text_color; ?>;			              <?php } ?>
">
  <div class="section-content">
    <div class="container">
      <div class="row mb-3">
        <div class="col-12">
          <h4><?php echo $section_title; ?></h4>
        </div>
      </div>
      <div class="card-deck">
        <div class="card shadow border-0 mg-md-4">
          <div class="card-body">
            <p class="card-text"><?php echo $first_section; ?></p>
          </div>
        </div>
      
	  	  <div class="card shadow border-0 mg-md-4">
          <div class="card-body">
            <p class="card-text"><?php echo $second_section; ?></p>
          </div>
        </div>

		    <div class="card shadow border-0 mg-md-4">
          <div class="card-body">
          	<p class="card-text"><?php echo $third_section; ?></p>
        	</div>
      	</div>
    	</div>
		</div>
  </div>
</div>