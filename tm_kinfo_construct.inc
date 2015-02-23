<?php 
// This calendar code was originally designed for: http://spacestationplaza.com/calendar.php

// Author: Anthony R. Fogleman coder@uptimehosting.com
// Create date: Dec 15, 2009
// Modifed last: Nov 3, 21013

function start_new_kinshow($this_instance_settings) {

// Include settings and date actions
	$somvealue = include(dirname(__FILE__).'/lib/settings_dates.inc');

// Engage Output Buffer ===================================== CONTENT BEGINS ====
	ob_start();


// Figure dates and kin
	$temp = include('lib/prep_for_kin.inc');


// Output the Form to De-Code a date

// FOR WIDGET ONLY Set the starting visibility of the main section
if (isset($this_instance_settings['display_decoder'])) {
	$display_decoder = $this_instance_settings['display_decoder'];
} else {$display_decoder = 'on';}

// Set the starting visibility of the main section

	if ($display_decoder === "on"){
		echo "<div class=\"nice_date\">$nice_date</div>";
		echo "<div id=\"tmc_form_container\" style=\"margin-bottom: 20px;\">";
		echo "<form method=\"GET\" action=\"".$_SERVER["REQUEST_URI"]."\">";
		echo "<table id=decode_table style=\"background-color: $decode_table_background_color; border: 0; padding: 0 0 0 0;\">\n";
		echo "<tr>";
		include(dirname(__FILE__).'/lib/cal_decode_form.inc');
		echo "</tr>\n";
		echo "</table></form>\n";
		echo "<div class=\"nice_date\">$tm_date_proper</div>";
		echo "</div>\n";
	}
 
// Pass some settings to the next script 
	$show_famous_events = get_option('show_famous_events'); // YES or NO

// Include kin-fo ======================================= MAIN SHOW =========================
	ob_start();
	$temp = include('lib/kin_for_widget.inc');
	$kin_info = ob_get_clean();
	echo "$kin_info";
// Include kin-fo ======================================= MAIN SHOW =========================

// FINALLY, AT THE VERY BOTTOM: 
// Tastefully display Links to Friends
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

// Stop Storing Output ...
	$tmc_kinfo_content = "<div id=\"tm_kinfo\">".ob_get_contents()."</div>";

// End Output Buffer
	$some_tmc_valuefornull = ob_end_clean();

// SEND OUTPUT ===============================================================
	return $tmc_kinfo_content;
}

?>