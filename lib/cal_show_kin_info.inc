<?php // cal_show_kin_info.inc

// To avoid database query, we simply load the output of the kin table into an array
// Get a file into an array.  In this example we'll go through HTTP to get
$lines = file(dirname(__FILE__).'/kin_lookup.txt'); // read into array $lines[]
$inc = 0;
foreach ($lines as $kin_line){
	$kin_line_array[$inc] = explode("|", $kin_line);
	$inc ++;
}

// Get the kin number for the day
	$this_day_kin_num = tmc_date_mysql_to_kin($this_mysql_date, $dcode_bcad);
// Change some calculations if it is LEAP YEAR, AND ON OR AFTER 2-28
	if ($this_day_kin_num > 260){$this_day_kin_num = $this_day_kin_num - 260;} // Do it once
	if ($this_day_kin_num > 260){$this_day_kin_num = $this_day_kin_num - 260;} // Do it again
// Get Greg date 
// Use adodb for a special timestamp
// adodb_mktime($hr, $min, $sec[, $month, $day, $year])
	$this_date_adodb_timestamp = adodb_mktime(0, 0, 0, $this_date_pcs[1], $this_date_pcs[2], $this_date_pcs[0]);
	//** FUNCTION adodb_mktime($hr, $min, $sec[, $month, $day, $year])
	$this_nice_date = adodb_date("D M j, Y", $this_date_adodb_timestamp);

// Instead of using the database, we're using an array made from the file kin_lookup.txt
	$Castle 			= $kin_line_array[$this_day_kin_num][2];
	$Wavespell 		= $kin_line_array[$this_day_kin_num][3];
	$Harmonic 		= $kin_line_array[$this_day_kin_num][4];
	$Color 			= $kin_line_array[$this_day_kin_num][5];
	$Tone 			= $kin_line_array[$this_day_kin_num][6];
	$Tribe 			= $kin_line_array[$this_day_kin_num][7];
	$Action_Essence 	= $kin_line_array[$this_day_kin_num][8];
	$Timecell 		= $kin_line_array[$this_day_kin_num][9];
	$TName_Essence 	= $kin_line_array[$this_day_kin_num][10];
	$Guiding_Power 	= $kin_line_array[$this_day_kin_num][11];
	$Portals 			= $kin_line_array[$this_day_kin_num][12];
	$Polar_Kin 		= $kin_line_array[$this_day_kin_num][13];

// ------------------- Get Guiding Power -------------------------
// First find out which tribe we're guided by from the destiny pattern
// Get tone num of this kin
	$tone_num = tone_name_to_num($Tone);
	// Get tribe num of this kin
	$tribe_num = tribe_name_to_num($Tribe);
	
// Get everything on this Kin

     $tribe_string = tribe_num_to_tribe_essences_del($tribe_num);
     $tribe_string_pcs = explode("|", $tribe_string);
     
     $tone_string = tone_num_to_tone_essences_del($tone_num);
     $tone_string_pcs = explode("|", $tone_string);

	$Tribe_Action	= $tribe_string_pcs[3];
	$Tribe_Essence	= $tribe_string_pcs[4];
	$Tribe_Power	= $tribe_string_pcs[5];

	$Tone_Action	= $tone_string_pcs[3];
	$Tone_Essence	= $tone_string_pcs[4];
	$Tone_Power	= $tone_string_pcs[2];


	// Get guiding power tribe num
	$Guid_pwr_tribe_num = guiding_power($tone_num, $tribe_num);

// Get tribe graphics for this kin
	$Tribe_Image = tribe_nm_to_img_num($Tribe);
	$Tone_Image = tone_nm_to_img_num_rev($Tone);

// Translate this kin to seo
	$this_day_kin_seof = translate_kin_to_seo($this_day_kin_num);

// Show Kin Images
	$popup_content .= "<div style=\"float: left; text-align: center;\">";

	$popup_content .= "<div style=\"float: left; text-align: center;\">";
	$popup_content .= "<img src=\"$tones_img_dir/$Tone_Image\" border=0 width=60 height=35 vspace=10 alt=\"$Tone\">";
	$popup_content .= "<br><img src=\"$tribes_img_dir/$Tribe_Image\" border=0 width=60 height=60 vspace=5 alt=\"$Tribe\"></a>";
	$popup_content .= "</div>\n";

// Show Kin Number and Text
	$popup_content .= "<div style=\"float: left; text-align: left; margin-top: 13px; margin-left: 13px;\">";
	$popup_content .= "<h3>Kin $this_day_kin_num</h3>";
	$popup_content .= "$Color<br>$Tone<br>$Tribe\n";
	$popup_content .= "</div>\n";

	$popup_content .= "</div>\n";

// Show affirmation for this Kin
    	$popup_content .= "<div style=\"text-align: center; margin-top: 13px; margin-left: 13px; min-width: 380px;\">";
	$popup_content .= "I $Tone_Power in order to $Tribe_Action<br>";
     $popup_content .= "$Action_Essence<br>";
     $popup_content .= "$Timecell<br>";
     $popup_content .= "$TName_Essence<br>";
     $popup_content .= "$Guiding_Power<br>";	
     $popup_content .= "$Polar_Kin<br>";	
    	$popup_content .= "</div>\n\n";


// Portal Info
	if ($Portals != ""){
	    	$popup_content .= "<div style=\"float: left; text-align: center; margin-top: 13px; width: 150px;\">";
	    	$popup_content .= "<div style=\"float: left;\">";
     	$popup_content .= "<img src=\"$portals_img_dir/portals_trans.gif\" border=0 width=30 height=60 alt=\"Galactic Portal Day\">";
	    	$popup_content .= "</div>\n\n";
	    	$popup_content .= "<div style=\"float: left; text-align: center; margin-left: 13px; width: 75px;\">";
     	$popup_content .= "$Portals\n\n";
	    	$popup_content .= "</div>\n\n";
	    	$popup_content .= "</div>\n\n";
	}

// Castle Info
    	$popup_content .= "<div style=\"float: left; text-align: center; width: 150px;\">";

    	$popup_content .= "<div style=\"float: left; text-align: left;\">";
    	$popup_content .= "Castle: $Castle - ". tmc_castle_num_to_name($Castle);
    	$popup_content .= "</div>\n\n";

// Wevespell Info
	$wavespell_info = tmc_wavespell_num_to_name($Wavespell);
    	$popup_content .= "<div style=\"float: left; text-align: left; \">";
    	$popup_content .= "Wavespell: $Wavespell - $wavespell_info<br>";
    	$popup_content .= "</div>\n\n";

    	$popup_content .= "</div>\n\n";

	if ($_GET[show_famous_events] == "YES"){

// Link to SSP -- need to get options before we can display this
     	$ssp_link = "<a href=\"http://spacestationplaza.com/13-moon-dreamspell-calendar/$Color-$Tone-$Tribe\" target=\"_blank\">";
         	$popup_content .= "<br clear=\"both\">\n";
         	$popup_content .= "<div style=\"float: left; text-align: left; margin-top: 13px;\">";
         	$popup_content .= $ssp_link."Famous Events on Kin $this_day_kin_num</a>";
         	$popup_content .= "</div>\n\n";
	}
    	$popup_content .= "<br clear=\"both\">\n\n";


echo "$popup_content";

?>