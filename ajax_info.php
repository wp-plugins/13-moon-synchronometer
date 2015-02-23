<?php // ajax_info.php

// This is the program that comes up in the ThickBox ajax modal dialog box - WordPress-Friendly



// <input alt="http://u-ching.com/wp-content/plugins/13-moon-synchronometer/ajax_info.php?height=300&amp;width=280&amp;date=2015-2-16&amp;purl=http://u-ching.com/wp-content/plugins&amp;ucd_locale=en_EN&amp;show_famous_events=YES&amp;rurl_enc_posts_del=&amp;tm_date_proper=NS1.27.8.10" title="Monday 16 February 2015" class="thickbox" type="button" value="10" id="super-tony-tmc-lo">



// Turn of annoying warnings
error_reporting(E_ERROR);
// error_reporting(E_ALL);


// Get MY Functions
if (function_exists('tmc_date_mysql_to_kin')){} else {	include(dirname(__FILE__).'/lib/functions.inc'); }

// Using ADOdb Date Time Library -- and only calling once in case the calendar is on the page twice
if (function_exists('adodb_date_test_date')){} else { include(dirname(__FILE__).'/lib/adodb-time.inc.php'); }

// Get some of the GET vars

// Start by retrieving the plugin Url
$purl = $_GET['purl'];

// Get the language
$ucd_locale = $_GET['ucd_locale'];

// Get the posts
$rurl_enc_posts_del = $_GET['rurl_enc_posts_del'];

// Get the official date code
$this_tm_date_proper = $_GET['tm_date_proper'];

$show_famous_events = $_GET['show_famous_events'];

/*
<input alt="http://uptimehosting.com/sandbox/wp-content/plugins/13-moon-synchronometer/ajax_info.php?height=300&amp;width=280&amp;date=2015-2-11&amp;purl=http://uptimehosting.com/sandbox/wp-content/plugins&amp;ucd_locale=en_EN&amp;show_famous_events=YES&amp;rurl_enc_posts_del=&amp;tm_date_proper=NS1.27.8.5" title="Wednesday 11 February 2015" class="thickbox" type="button" value="5" id="super-tony-tmc-lo">

http://uptimehosting.com/sandbox/wp-content/plugins/13-moon-synchronometer/ajax_info.php?
height=300&amp;
width=280&amp;
date=2015-2-11&amp;
purl=http://uptimehosting.com/sandbox/wp-content/plugins&amp;
ucd_locale=en_EN&amp;
show_famous_events=YES&amp;
rurl_enc_posts_del=&amp;
tm_date_proper=NS1.27.8.5

echo "show_famous_events: $show_famous_events";

exit;


*/


if (strlen($rurl_enc_posts_del) > 10){
	$posts_pcs = explode("|", $rurl_enc_posts_del);
	
	$inc = 0;
	$post_listing = "";
	foreach ($posts_pcs as $dummy){
		$post_listing .= '<li>';
		$post_listing .= '<a href="'.$posts_pcs[$inc].'" title="'.$posts_pcs[$inc + 1].'">';
		$inc++;
		$post_listing .= $posts_pcs[$inc];
		$post_listing .= '</a></li>';
		
		$inc++;
		
		if ($posts_pcs[$inc] == ""){
		break;
		}
	}
	
	echo "Posts (".($inc / 2).")";
	echo "$post_listing";

}

// http://sandbox.web/wp/experimental-plugin-space/   %3E http://sandbox.web/wp/?p=10

// Directory paths for important things
$moons_img_dir 	= "$purl/13-moon-synchronometer/images/moons";
$plasmas_img_dir 	= "$purl/13-moon-synchronometer/images/plasmas";
$tones_img_dir	 	= "$purl/13-moon-synchronometer/images/tones";
$seals_img_dir 	= "$purl/13-moon-synchronometer/images/seals";
$portals_img_dir 	= "$purl/13-moon-synchronometer/images/portals";
$ajax_info 		= "$purl/13-moon-synchronometer/ajax_info.php";

// Determine which mode to run in
if (isset($_GET['kin_num'])){

	$kin_num = $_GET[kin_num];
	echo "Running by KIN method: kin_num: $kin_num <br><br>"; 

} elseif (isset($_GET['date'])){

	$this_mysql_date = $_GET['date'];
//	echo "Running by DATE method: this_mysql_date: $this_mysql_date <br><br>";

// Break up date for functions
	$this_date_pcs = explode("-", $this_mysql_date);

// Check to see if this day is LEAP DAY
     $this_mysql_date_pieces = explode("-", $this_mysql_date);
     if (($this_mysql_date_pieces[1] == 2)&&($this_mysql_date_pieces[2] == 29)){
     	$prior_yr  = $this_mysql_date_pieces[0];
     	$prior_mysql_date_ckld = $this_mysql_date_pieces[0]."-02-29";
     	if (ms_date_is_leapday($prior_mysql_date_ckld)){
              	$gad_info = "<div style=\"float: left; text-align: left; margin-left: 0px;\">\n";
          	ob_start();
          	$temp = include('lib/cal_galactic_align_day.inc');
          	$gad_info .= ob_get_clean();
               $gad_info .= "</div>\n";
          	echo "$gad_info";
          	echo "<br clear=\"both\">";
     	}
     } // End if it's leap day


// Check to see if it's either day before or after Day out of Time (Jul 25)
	if ((($this_mysql_date_pieces[1] == 7)&&($this_mysql_date_pieces[2] == 24))||(($this_mysql_date_pieces[1] == 7)&&($this_mysql_date_pieces[2] == 26))){
	// This is DOOT special Linke to a Popup for it
		$doot_link = "<a href=\"$ajax_info?date=$this_mysql_date_pieces[0]-7-25&purl=".$purl."\" title=\"The Day out of Time\" class=\"thickbox\">Day Out of Time</a><br>";
		$include_doot_link = "YES";
     } else {$include_doot_link = "NO";}  // End if it's DOOT

// Include link to DOOT
     if ($include_doot_link == "YES"){
         	$doot_link .= "<div style=\"float: left; margin-left: 13px; margin-top: 13px;\">";
		$doot_link .= "</div>";
		$doot_link .= "<br clear=\"both\">";
		echo "$doot_link";
     }

// If the date is xxxx-07-25 it's the Day out of Time
	if (($this_mysql_date_pieces[1] == 7)&&($this_mysql_date_pieces[2] == 25)){

          $gad_info = "<div style=\"float: left; text-align: left; margin-left: 0px;\">\n";
          ob_start();
          $temp = include('lib/cal_day_out_of_time.inc');
          $doot_popup_contents .= ob_get_clean();
          $doot_popup_contents .= "</div>\n";
          echo "$doot_popup_contents";
          echo "<br clear=\"both\">";
	}

// Get Greg date 
// Use adodb for a special timestamp
// adodb_mktime($hr, $min, $sec[, $month, $day, $year])
	$this_date_adodb_timestamp = adodb_mktime(0, 0, 0, $this_date_pcs[1], $this_date_pcs[2], $this_date_pcs[0]);
	//** FUNCTION adodb_mktime($hr, $min, $sec[, $month, $day, $year])
	$this_nice_date = adodb_date("D M j, Y", $this_date_adodb_timestamp);

// Let's get the date
     $this_day_year = $this_date_pcs[0];
     $this_day_mon = $this_date_pcs[1];
     $this_day_day = $this_date_pcs[2];

// Display Nice Date
// Uses locale() above
     if (($this_date_pcs[0] >= 1902)&&($this_date_pcs[0] <= 2037)){
// strtotime() has a range limit between Fri, 13 Dec 1901 20:45:54 GMT and Tue, 19 Jan 2038 03:14:07 GMT
     	$this_nice_translated_date = utf8_encode(strftime("%A %e %B %Y", strtotime("$this_day_mon/$this_day_day/$this_day_year")));
	} else {
		$this_nice_translated_date = $this_nice_date;
	}

// Display the nice Gregorian date
    	$nice_date = "";
    	$nice_date .= "<div style=\"float: left; text-align: center; margin-left: 0px;\">";
	$nice_date .= $this_nice_translated_date;
     $nice_date .= "</div>\n";
     $nice_date .= "<br clear=both>\n";
     
     

// Include kin-fo

// NS - Style DATE -- tm_date_proper
	$kin_info = "<div class=\"proper_date\">$this_tm_date_proper</div>";


$kin_info .= $capture_to_test;


    	$kin_info .= "<div style=\"float: left; text-align: center; margin-left: 0px;\">\n";
	ob_start();

	$temp = include('lib/prep_for_kin.inc');
	
	$temp = include('lib/kin_for_popup.inc');

	$kin_info .= ob_get_clean();
     $kin_info .= "</div>\n";
	echo "$kin_info";
	echo "<br clear=\"both\">";
// Moon Image and Phases
    	$moon_info .= "<div style=\"float: left; text-align: center; margin-left: 0px;\">\n";
	ob_start();
	$temp = include('lib/cal_show_moon_phases.inc');
	$moon_info .= ob_get_clean();
     $moon_info .= "</div>\n";
	echo "$moon_info";

} elseif (isset($_GET['month_num'])){
	$month_num = $_GET['month_num'];
	echo "Running by MONTH method: month_num: $month_num <br><br>";
} elseif (isset($_GET['day_num'])){
//	echo "Running by DAY method: day_num: $day_num <br><br>";
	$day_num = $_GET['day_num'];
	$maya_day_name = $_GET['maya_day_name']; // for images
//	echo "$maya_day_name - $day_num";
	echo "<br><br><br>";
	echo "<div id=\"plasma$day_count\" title=\"$this_moon_name $maya_day_name\">";
	echo "<img src=\"$plasmas_img_dir/$maya_day_name".".png\" alt=\"$maya_day_name\" width=30 height=30>";
	echo "</div>";
}
?>
<div style="text-align: right;" class="close_window">
<input type="button" id="Whatever" value="Close Window" onclick="tb_remove()">
</div>