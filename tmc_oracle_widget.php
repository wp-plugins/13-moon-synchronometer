<?php


class tmc_oracle_widget extends WP_Widget {
 	function tmc_oracle_widget() {
		$widget_options = array(
			'classname'=> 'tmc_oracle_widget_class',
			'description'=> __('Show the daily 13-moon kin oracle', 'tmc_oracle_widget_desc'),
		);
		$this->WP_Widget('tmc_oracle_widget',  __('13 Moon Oracle', 'tmc_oracle_widget'), $widget_options);
	}
  
// widget form creation
     function form($instance) {
     	     // Check values
	     if( $instance) {
	          $title = esc_attr($instance['title']);
	          $display_onload = esc_attr($instance['display_onload']);
	          $display_decoder = esc_textarea($instance['display_decoder']);
	     } else {
	          $title = 'Today Kin';
	          $display_onload = 'off';
	          $display_decoder = 'on';
	     }
?>
	     <p>
	     <label for="<?php echo $this->get_field_id('title'); ?>"><?php _e('Widget Title', 'tmc_oracle_widget'); ?></label>
	     <input class="widefat" id="<?php echo $this->get_field_id('title'); ?>" name="<?php echo $this->get_field_name('title'); ?>" type="text" value="<?php echo $title; ?>" />
	
	     <select id="<?php echo $this->get_field_id('display_onload'); ?>" name="<?php echo $this->get_field_name('display_onload'); ?>">
	     <option value="on"<?php if ($display_onload === "on"){echo " SELECTED";}?>>on</option>
	     <option value="off"<?php if ($display_onload === "off"){echo " SELECTED";}?>>off</option>
	     </select>
	     Start With Info Expanded - (<?php echo $display_onload; ?>) <br>
	
	     <select id="<?php echo $this->get_field_id('display_decoder'); ?>" name="<?php echo $this->get_field_name('display_decoder'); ?>">
	     <option value="on"<?php if ($display_decoder === "on"){echo " SELECTED";}?>>on</option>
	     <option value="off"<?php if ($display_decoder === "off"){echo " SELECTED";}?>>off</option>
	     </select>
	     Display Decoder - (<?php echo $display_decoder; ?>)

	     </p>More <a href="options-general.php?page=13-moon-synchronometer/settings.inc">Customize 13-moon Settings</a>
<?php
	}

// update widget
     function update($new_instance, $old_instance) {
           $instance = $old_instance;
           // Fields
           $instance['title'] = strip_tags($new_instance['title']);
           $instance['display_onload'] = strip_tags($new_instance['display_onload']);
           $instance['display_decoder'] = strip_tags($new_instance['display_decoder']);
          return $instance;
     }

// display widget
     function widget($args, $instance) {
        extract( $args );
        // these are the widget options
        $title = apply_filters('widget_title', $instance['title']);

        echo $before_widget;
        // Display the widget
        echo '<div class="widget-text tmc_oracle_widget_box">';
     
        // Check if title is set
        if ( $title ) {
           echo $before_title . $title . $after_title;
        }

// Include output
	$tmc_content = start_new_oracle($instance); // Pass over some vars
	echo '<div class="tmc_oracle_widget_textarea">'.$tmc_content.'</div>';
        echo '</div>';
	echo $after_widget;
     }
}

// register widget
add_action('widgets_init', create_function('', 'return register_widget("tmc_oracle_widget");'));


