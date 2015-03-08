<?php
/*
Plugin Name: 13-Moon Synchronometer
Plugin URI: http://anthonyfogleman.com/blog/13-moon-synchronometer-wp-plugin/
Description: Natural Time harmonic measurement and synchronizing tools include a decoder, 13 month grid, kin, wavespell, oracle, shows posts and affirmations in English, Spanish and Dutch.   Works harmoniously with other Dreamspell plugins, changing each day and when date is decoded. Use the widgets in your sidebars or shortcodes: [show-calendar] [show-kin] [show-oracle] [show-wavespell]
Version: 2.1.1
Author: Anthony R. Fogleman
Author URI: http://anthonyfogleman.com
License: GPLv2 or later
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
 * THE Proper way to enqueue scripts and styles 
*/

/*  Add Custom Styles */
function add_styles(){
// This is the calendar's css file - we NEED IT
	wp_register_style( 'thirteen-moon-cal-style', plugins_url('/css/tmc-synchronometer.css', __FILE__), false, '1.0.0', 'all');
	wp_register_script( 'custom_jquery', plugins_url('/js/jquery_scripts.js', __FILE__), array('jquery'), '2.5.1' );
}
add_action('init', 'add_styles');

/*  Enqueue scripts and styles  */
function load_scripts(){
	wp_enqueue_script( 'jquery' );
	wp_enqueue_script( 'thickbox' );
	wp_enqueue_script( 'custom_jquery' );
	wp_enqueue_style( 'thickbox' );
	wp_enqueue_style( 'thirteen-moon-cal-style' );
}
add_action('wp_enqueue_scripts', 'load_scripts');
// -- done registering style and scripts

// Include some files for each program and widget

// Include 13 Moon Synchronometer Display FUNCTION: start_new_calendar() -- The main program is ONE function
include('tm_cal_construct.inc');
include('tmc_monthly_widget.php');

// NEW VER 2.0.9 --- Tone, Seal, Affirmation display ONLY Widget -- ONE function
include('tm_kinfo_construct.inc');
include('tmc_kinfo_widget.php');

// NEW VER 2.0.9 --- Tone, Seal, Affirmation display ONLY Widget -- ONE function
include('tm_oracle_construct.inc');
include('tmc_oracle_widget.php');

// NEW VER 2.0.9 --- Tone, Seal, Affirmation display ONLY Widget -- ONE function
include('tm_wavespell_construct.inc');
include('tmc_wavespell_widget.php');

// Include some files for each shortcode

// This code creates the ability to use shortcodes in the sidebar
add_filter('widget_text', 'do_shortcode');

// Make a shortcode for Calendar Monthly View
add_shortcode('show-calendar', 'start_new_calendar');

// Shortcode for Kin View
add_shortcode('show-kin', 'start_new_kinshow');

// Shortcode for Oracle View
add_shortcode('show-oracle', 'start_new_oracle');

// Shortcode for Wavespell View
add_shortcode('show-wavespell', 'start_new_wavespell');

// Include wp menu and settings file for administrator // create custom plugin settings menu
include('settings.inc');
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