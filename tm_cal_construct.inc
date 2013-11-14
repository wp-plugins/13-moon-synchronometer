<?php 
// This calendar code was originally designed for: http://spacestationplaza.com/calendar.php

// Author: Anthony R. Fogleman coder@uptimehosting.com
// Create date: Dec 15, 2009
// Modifed last: Nov 3, 21013

function start_new_calendar() {

// Directory paths for images
	$moons_img_dir = plugins_url().'/13-moon-synchronometer/images/moons';
	$plasmas_img_dir = plugins_url().'/13-moon-synchronometer/images/plasmas';
	$tones_img_dir = plugins_url().'/13-moon-synchronometer/images/tones';
	$tribes_img_dir = plugins_url().'/13-moon-synchronometer/images/tribes';
	$portals_img_dir = plugins_url().'/13-moon-synchronometer/images/portals';
	$ajax_info = plugins_url().'/13-moon-synchronometer/ajax_info.php';


// Adjust the dates if either DOOT or LEAP were requested
     if (($_GET[dcode_mo] == 2) && ($_GET[dcode_day] > 28)) {$_GET[dcode_day] = 1;$_GET[dcode_mo] = 3;}
     if (($_GET[dcode_mo] == 4) && ($_GET[dcode_day] > 30)) {$_GET[dcode_day] = 1;$_GET[dcode_mo] = 5;}
     if (($_GET[dcode_mo] == 6) && ($_GET[dcode_day] > 30)) {$_GET[dcode_day] = 1;$_GET[dcode_mo] = 7;}
     if (($_GET[dcode_mo] == 9) && ($_GET[dcode_day] > 30)) {$_GET[dcode_day] = 1;$_GET[dcode_mo] = 10;}
     if (($_GET[dcode_mo] == 11) && ($_GET[dcode_day] > 30)) {$_GET[dcode_day] = 1;$_GET[dcode_mo] = 12;}
// For Day Out of Time, we record original request
     if (($_GET[dcode_mo] == 7) && ($_GET[dcode_day] == 25)) {$_GET[dcode_day] = 26; $day_out_of_time_flag = "YES";}

// Using ADOdb Date Time Library -- and only calling once in case the calendar is on the page twice
     if (function_exists('adodb_date_test_date')){} else {
     	include(dirname(__FILE__).'/lib/adodb-time.inc.php');
     }

     // Get Functions
     if (function_exists('tmc_date_mysql_to_kin')){} else {
     	include(dirname(__FILE__).'/lib/functions.inc');
     }

// Set defaults
	$decode_table_background_color = "#".get_option('decode_table_background_color');
	if ($decode_table_background_color == "#"){$decode_table_background_color = "#eee";}

	$moon_table_background_color = "#".get_option('moon_table_background_color');
	if ($moon_table_background_color == "#"){$moon_table_background_color = "#ddd";}

	$plasma_table_background_color = "#".get_option('plasma_table_background_color');
	if ($plasma_table_background_color == "#"){$plasma_table_background_color = "#fff";}

	$permit_credits = get_option('permit_credits');

// Engage Output Buffer ===================================== CONTENT BEGINS ====
	ob_start();
// Start outputting 

     // Get the date requested and return properly formatted date 
     if ((isset($_GET[dcode_yr]))&&(isset($_GET[dcode_yr]))&&(isset($_GET[dcode_yr]))){
     // Assign GET to vars
     	$dcode_yr 	= $_GET['dcode_yr'];
     	$dcode_mo 	= ltrim($_GET['dcode_mo'], '0');
     	$dcode_day 	= ltrim($_GET['dcode_day'], '0');
     	$dcode_bcad 	= $_GET[dcode_bcad];
     } else {
     // If no GETS, then use today's date
     	$dcode_yr 	= adodb_date("Y");
     	$dcode_mo 	= adodb_date("n");
     	$dcode_day 	= adodb_date("j");
     	$dcode_bcad 	= "AD";
     }

// Get today's date
	$today_greg_month =  date("n"); // month numeral
	$today_greg_month_abbrev =  date("M"); // month numeral
	$today_greg_day =  date("j"); // day numeral without leading zeros
	$today_greg_month_num =  date("m"); // 
	$today_greg_day_num =  date("d"); // 
	$today_greg_year_num =  date("Y"); // 

// BEGIN OUTPUT ===============================================================

     // Format for MySQL
     $mysql_date = $dcode_yr."-".$dcode_mo."-".$dcode_day;
     // Assign to AD if no entry for dcode_bcad
     if (($dcode_bcad !== "BC")||($dcode_bcad !== "AD")){
     	$dcode_bcad = "AD";
     }

// -------- Build the calendar output -----  //
	include(dirname(__FILE__).'/lib/cal_build_cal_table.inc'); // Generates a scalar: $cal_display


// Output the Form to De-Code a date
     echo "<table id=decode_table width=\"100%\" style=\"background-color: $decode_table_background_color; border: 0; padding: 0 0 0 0; margin-top: 13px;\">\n";
	echo "<tr>";
	include(dirname(__FILE__).'/lib/cal_decode_form.inc');
	echo "</tr>\n";
	echo "</table>\n";

	if ($this_moon_name == "Magnetic"){
		$doot_link = "<a href=\"$ajax_info?width=380&date=$this_mysql_date_pieces[0]-7-25&purl=".plugins_url()."\" title=\"The Day out of Time $this_mysql_date_pieces[0]\" class=\"thickbox\">Day Out of Time $this_mysql_date_pieces[0]</a><br>";

// Output the Header with days of Plasmas
          echo "<table width=\"100%\" style=\"background-color: $plasma_table_background_color; border: 0; padding: 0 0 0 0; margin-top: 13px;  margin-bottom: 13px;\">\n";
     	echo "<tr>\n";
     	echo "<th style=\"text-align: center;\">";
     	echo "<h1>$doot_link</h1>\n";
		echo "</th>\n";
     	echo "</tr>\n";
     	echo "</table>\n\n";
	}

// Show this page's header -- moon, info, and form
     echo "<table width=\"100%\" style=\"background-color: $moon_table_background_color; border: 0; padding: 0px 0px 0px 0; margin: 0;\">\n";
// Link to last month
	echo "<tr>\n";
	echo "<td style=\"text-align:left; border: 0; padding: 0px 0px 0px 0; width: 1%; vertical-align: middle;\">";
	echo "<a href=\"?dcode_yr=$last_moon_first_yr&amp;dcode_mo=$last_moon_first_mo&amp;dcode_day=$last_moon_first_day\" title=\"Go back one moon\">";
	echo "<i class=\"change_month\">&lt;</i>";
	echo "</a>";
	echo "</td>";
// Moon Info
	echo "<td style=\"text-align: center; border: 0; padding: 0px 0px 0px 0;\">";
	echo "<h4 style=\"padding: 0; margin: 0; font-size: 13px;\" >$this_moon_name </h4>MOON $this_moon_num";
	echo "</td>";
// Link to next month
	echo "<td style=\"text-align:right; border: 0; padding: 0px 0px 0px 0; width: 1%; vertical-align: middle;\">";
	echo "<a href=\"?dcode_yr=$next_moon_first_yr&amp;dcode_mo=$next_moon_first_mo&amp;dcode_day=$next_moon_first_day\" title=\"Advance one moon\">";
	echo "<i class=\"change_month\">&gt;</i>";
	echo "</a>";

// &gt;

	echo "</td>";
	echo "</tr>\n";
	echo "</table>\n";

// Output the Header with days of Plasmas
     echo "<table width=\"100%\" style=\"background-color: $plasma_table_background_color; border: 0; padding: 0 0 0 0; margin-top: 13px;  margin-bottom: 13px;\">\n";
	echo "<tr>";
	include(dirname(__FILE__).'/lib/cal_maya_days_row.inc');
	echo "</tr>\n";
	echo "</table>\n";

     // OUTPUP compiled calendar to the content buffer
	echo "$cal_display";


// Show Day out of Time Link
	if ($this_moon_name == "Cosmic"){
		$doot_link = "<a href=\"$ajax_info?width=380&date=$this_mysql_date_pieces[0]-7-25&purl=".plugins_url()."\" title=\"The Day out of Time $this_mysql_date_pieces[0]\" class=\"thickbox\">Day Out of Time $this_mysql_date_pieces[0]</a><br>";

// Output the Header with days of Plasmas
          echo "<table width=\"100%\" style=\"background-color: $plasma_table_background_color; border: 0; padding: 0 0 0 0; margin-top: 13px;  margin-bottom: 13px;\">\n";
     	echo "<tr>\n";
     	echo "<th style=\"text-align: center;\">";
     	echo "<h1>$doot_link</h1>\n";
		echo "</th>\n";
     	echo "</tr>\n";
     	echo "</table>\n\n";
	}

// Show Links to Friends

     if ($permit_credits === "YES"){
         	echo "<div class=tmc_ads>";
         	echo "<div id=\"morestuff\">";
         	echo "<a target=\"_BLANK\" href=\"http://lawoftime.org/\" title=\"Foundation for the Law of Time\">FLT</a>";
         	echo " ";
         	echo "<a target=\"_BLANK\" href=\"http://spacestationplaza.com/\" title=\"Space Station Plaza\">SSP</a>";
         	echo " ";
         	echo "<a target=\"_BLANK\" href=\"http://www.u-ching.com/\" title=\"uChing Network\">uCHING</a>";
         	echo "</div>";
         	echo "</div>";

	}

// Stop Storing Output ...
	$tmc_content = "<div id=\"tm_synchronometer\">".ob_get_contents()."</div>";

// End Output Buffer
	$some_tmc_valuefornull = ob_end_clean();

// SEND OUTPUT ===============================================================
	return $tmc_content;
}

?>