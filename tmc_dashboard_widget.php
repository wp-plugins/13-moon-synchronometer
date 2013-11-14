<?php
class tmc_plugin_widget extends WP_Widget {
 
    // constructor
    function tmc_plugin_widget() {
		parent::WP_Widget(false, $name = __('13-Moon Calendar', 'wp_widget_plugin') );
    }

// widget form creation
     function form($instance) {
     
     // Check values
     if( $instance) {
          $title = esc_attr($instance['title']);
          $text = esc_attr($instance['text']);
          $textarea = esc_textarea($instance['textarea']);
     } else {
          $title = '';
          $text = '';
          $textarea = '';
     }
     ?>
     
     <p>
     <label for="<?php echo $this->get_field_id('title'); ?>"><?php _e('Widget Title', 'wp_widget_plugin'); ?></label>
     <input class="widefat" id="<?php echo $this->get_field_id('title'); ?>" name="<?php echo $this->get_field_name('title'); ?>" type="text" value="<?php echo $title; ?>" />
     </p>
More <a href="options-general.php?page=13-moon-synchronometer/settings.inc">Customize 13-moon Settings</a>

     <?php
     }

// update widget
     function update($new_instance, $old_instance) {
           $instance = $old_instance;
           // Fields
           $instance['title'] = strip_tags($new_instance['title']);
           $instance['text'] = strip_tags($new_instance['text']);
           $instance['textarea'] = strip_tags($new_instance['textarea']);
          return $instance;
     }

	// widget display
     // display widget
     function widget($args, $instance) {
        extract( $args );
        // these are the widget options
        $title = apply_filters('widget_title', $instance['title']);
        $text = $instance['text'];
        $textarea = $instance['textarea'];
        echo $before_widget;
        // Display the widget
        echo '<div class="widget-text wp_widget_plugin_box">';
     
        // Check if title is set
        if ( $title ) {
           echo $before_title . $title . $after_title;
        }
     
// here's hte output of tmc
// Include output
// include('chron_output.inc');
		$tmc_content = start_new_calendar();

          echo '<p class="wp_widget_plugin_textarea">'.$tmc_content.'</p>';
        echo '</div>';

		echo $after_widget;
     }

}

// register widget
add_action('widgets_init', create_function('', 'return register_widget("tmc_plugin_widget");'));