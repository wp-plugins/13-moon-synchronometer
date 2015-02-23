<?php 
// This calendar code was originally designed for: http://spacestationplaza.com/calendar.php

// Author: Anthony R. Fogleman coder@uptimehosting.com
// Create date: Dec 15, 2009
// Modifed last: Nov 3, 21013

function start_new_calendar() {

// Include settings and date actions
	$somvealue = include(dirname(__FILE__).'/lib/settings_dates.inc');

// -------- Build the calendar output -----  //
	include(dirname(__FILE__).'/lib/cal_build_cal_table.inc'); // Generates a scalar: $cal_display

// Engage Output Buffer ===================================== CONTENT BEGINS ====
	ob_start();

// Start with a container DIV
	echo "<div id=\"tm_synchronometer\">";

// Output the Form to De-Code a date
	echo "<div id=\"tmc_form_container\">";
	echo "<form method=\"GET\" action=\"".$_SERVER["REQUEST_URI"]."\">";
	echo "<table id=decode_table style=\"background-color: $decode_table_background_color; border: 0; padding: 0 0 0 0;\">\n";
	echo "<tr>";
	include(dirname(__FILE__).'/lib/cal_decode_form.inc');
	echo "</tr>\n";
	echo "</table></form>\n";
	echo "</div>\n";

	// Asking for DOOT July 25 -- We simply need to get the proper cycles
	if (($dcode_mo === "7") && ($dcode_day === "25")){
		echo "<div class=\"doot_div_cl\" id=\"doot_div_id\">";
		echo "<div class=\"doot_img\">";
		echo "<img src=\"".$img_dir."/Rainbow-Bridge.png\" alt=\"Rainbow Bridge\">";
		echo "</div>";	
		echo "<div class=\"doot_txt\">";
		echo "<P>July 25 ".$dcode_yr."<br>".$tm_date_proper."</P><P><i class=\"doot_itext\">The Day<br>Out of Time</i></P>";
		echo "</div>";
		echo "</div>";	
	} else {
		if ($this_moon_num == "1"){
			$doot_link = "<a href=\"$ajax_info?width=380&date=$this_mysql_date_pieces[0]-7-25&purl=".plugins_url()."\" title=\"The Day out of Time $this_mysql_date_pieces[0]\" class=\"thickbox\">Day Out of Time $this_mysql_date_pieces[0]</a><br>";
			// Output the Header with days of Plasmas
		        echo "<table style=\"background-color: $plasma_table_background_color; border: 0; padding: 0 0 0 0;\">\n";
		     	echo "<tr>\n";
		     	echo "<th style=\"text-align: center;\">";
		     	echo "<h1>$doot_link</h1>\n";
				echo "</th>\n";
		     	echo "</tr>\n";
		     	echo "</table>\n\n";
		}

		// Change Locale, as needed // What language are you using?
		$ucd_locale = get_locale();
		
		// What language are you using? // $ucd_locale = get_locale();
		if ($ucd_locale == "es_ES"){$file_fun_lang_ext = "_es";} 
		elseif ($ucd_locale == "nl_NL"){$file_fun_lang_ext = "_nl";} 
		else {$file_fun_lang_ext = "_en";}
		
		// Choose the correct file
		// To avoid database query, we simply load the output of the kin table into an array
		// Get a file into an array.  In this example we'll go through HTTP to get
		$lines = file(dirname(__FILE__).'/lib/kin_lookup'.$file_fun_lang_ext.'.txt'); // read into array $lines[]
		$inc = 0;
		foreach ($lines as $kin_line){
		$kin_line_array[$inc] = explode("|", $kin_line);
		$inc ++;
		}
		
		// Get the translated tone
		$this_moon_name		 = $kin_line_array[$this_moon_num][6];
		$this_moon_name		 = utf8_encode($this_moon_name);
		
		
		// Use 2 functions to get the correct 13moon date
		$tmc_yrs_since_array = tmc_ns_yr_nums($dcode_yr, $dcode_mo, $dcode_day); // returns array of two items: x x
		$tmc_ns_first_cycle = $tmc_yrs_since_array[0];
		$tmc_ns_second_cycle = $tmc_yrs_since_array[1];
		
		// $tmc_ns_first_cycle
		if ($tmc_ns_first_cycle == "-0"){
		$tmc_ns_first_cycle = str_replace("-", "", "$tmc_ns_first_cycle");
		}
		
	// Show this page's header -- moon, info, and form
		echo "<table style=\"background-color: $moon_table_background_color; border: 0; padding: 0px 0px 0px 0; margin: 0;\">\n";
		echo "<tr>\n";
		echo "<td style=\"text-align:left; border: 0; padding: 0px 0px 0px 0; width: 1%; vertical-align: middle;\">";
		echo "<a href=\"?dcode_yr=$last_moon_first_yr&amp;dcode_mo=$last_moon_first_mo&amp;dcode_day=$last_moon_first_day\" title=\"Go back one moon\">";
		echo "<i class=\"change_month\">&lt;</i>";
		echo "</a>";
		echo "</td>";
	// Moon Info
		echo "<td style=\"text-align: center; border: 0; padding: 0px 0px 0px 0;\">";
		echo "<h4>$this_moon_name $tr_txt_moon $this_moon_num</h4>$tm_date_proper";
		echo "</td>";
	// Link to next month
		echo "<td style=\"text-align:right; border: 0; padding: 0px 0px 0px 0; width: 1%; vertical-align: middle;\">";
		echo "<a href=\"?dcode_yr=$next_moon_first_yr&amp;dcode_mo=$next_moon_first_mo&amp;dcode_day=$next_moon_first_day\" title=\"Advance one moon\">";
		echo "<i class=\"change_month\">&gt;</i>";
		echo "</a>";
		echo "</td>";
		echo "</tr>\n";
		echo "</table>\n";

// Output the Header with days of Plasmas
		echo "<table id=\"plasma_table\" style=\"background-color: $plasma_table_background_color; border: 0; padding: 0 0 0 0;\">\n";
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
			echo "<table style=\"background-color: $plasma_table_background_color; border: 0; padding: 0 0 0 0; margin-top: 13px;  margin-bottom: 13px;\">\n";
		     	echo "<tr>\n";
		     	echo "<th style=\"text-align: center;\">";
		     	echo "<h1>$doot_link</h1>\n";
			echo "</th>\n";
		     	echo "</tr>\n";
		     	echo "</table>\n\n";
		}
	}

// Show Links to Friends
     if ($permit_credits === "YES"){
         	echo "<div class=tmc_ads id=\"tmc_ads_id\">";
         	echo "<div id=\"morestuff\"  class=\"tmc_ad_class\">";
         	echo "<a class=tmc_ads target=\"_BLANK\" href=\"http://lawoftime.org/\" title=\"Foundation for the Law of Time\">FLT</a>";
         	echo " ";
         	echo "<a class=tmc_ads target=\"_BLANK\" href=\"http://spacestationplaza.com/\" title=\"Space Station Plaza\">SSP</a>";
         	echo " ";
         	echo "<a class=tmc_ads target=\"_BLANK\" href=\"http://www.u-ching.com/\" title=\"uChing Network\">uCHING</a>";
         	echo "</div>";
         	echo "</div>";
	}

// CLOSE beginning container DIV
	echo "</div>";

// Stop Storing Output ...
	$tmc_content = ob_get_contents();

// End Output Buffer
	$some_tmc_valuefornull = ob_end_clean();

// SEND OUTPUT ===============================================================
	return $tmc_content;
}

?>