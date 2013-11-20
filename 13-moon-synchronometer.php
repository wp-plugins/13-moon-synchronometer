<?php
/*
Plugin Name: 13-Moon Synchronometer
Plugin URI: http://anthonyfogleman.com/blog/13-moon-synchronometer-wp-plugin/
Description: The 13-Moon Synchronometer is a calendar of Natural Time and harmonic measurement tool synchronized with natural order. Your site will display a harmonic Calendar, list your posts, moon, kin, and more. Makes a widget you can drop in a sidebar or use shortcode [thirteen-moon-calendar] in post or page to synchronize with Natural Time.
Version: 1.4.2
Author: Anthony R. Fogleman
Author URI: http://anthonyfogleman.com
License: GPLv2
*/

/*  Copyright 2013  Anthony R. Fogleman  ( circle@uptimehosting.com )

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as 
    published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/**
 * Proper way to enqueue scripts and styles 
*/

/*  Add Custom Styles */
function add_styles(){
// This is the calendar's css file - we NEED IT
	wp_register_style( 'thirteen-moon-cal-style', plugins_url('/css/tmc-synchronometer.css', __FILE__), false, '1.0.0', 'all');
}
add_action('init', 'add_styles');

/*  Enqueue scripts and styles  */
function load_scripts(){
     wp_enqueue_script( 'jquery' );
     wp_enqueue_script( 'thickbox' );
     wp_enqueue_style( 'thickbox' );
	wp_enqueue_style( 'thirteen-moon-cal-style' );
}
add_action('wp_enqueue_scripts', 'load_scripts');
// -- done registering style and scripts

// Include dashboard widget for the sidebar calendar
include('tmc_dashboard_widget.php');

// This code creates the ability to use shortcodes in the sidebar
add_filter('widget_text', 'do_shortcode');

// Include calendar program function
include('tm_cal_construct.inc');

// Make a shortcode for full-page use
add_shortcode('thirteen-moon-calendar', 'start_new_calendar');

// Include wp menu and settings file
include('settings.inc');

// create custom plugin settings menu
add_action('admin_menu', 'tmc_admin_options_menu');

// To get admin menu "Settings" | Deactivate | Edit
function tmc_admin_settings_link( $links ) {
	$settings_link = '<a href="options-general.php?page=13-moon-synchronometer/settings.inc">Settings</a>';
  	array_push( $links, $settings_link );
  	return $links;
}
$plugin = plugin_basename( __FILE__ );
add_filter( "plugin_action_links_$plugin", 'tmc_admin_settings_link' );
?>