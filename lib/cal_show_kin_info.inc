<?php // cal_show_kin_info.inc

// Check the Language....

// What language are you using? // $ucd_locale = get_locale();
if ($ucd_locale == "es_ES"){$file_fun_lang_ext = "_es";} 
elseif ($ucd_locale == "nl_NL"){$file_fun_lang_ext = "_nl";} 
else {$file_fun_lang_ext = "_en";}

// Choose the correct file
// To avoid database query, we simply load the output of the kin table into an array
// Get a file into an array.  In this example we'll go through HTTP to get
$lines = file(dirname(__FILE__).'/kin_lookup'.$file_fun_lang_ext.'.txt'); // read into array $lines[]
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
// Get Greg date  // Use adodb for a special timestamp
// adodb_mktime($hr, $min, $sec[, $month, $day, $year])
$this_date_adodb_timestamp = adodb_mktime(0, 0, 0, $this_date_pcs[1], $this_date_pcs[2], $this_date_pcs[0]);
//** FUNCTION adodb_mktime($hr, $min, $sec[, $month, $day, $year])
$this_nice_date = adodb_date("D M j, Y", $this_date_adodb_timestamp);

// Instead of using the database, we're using an array made from the file kin_lookup.txt
// It relies on the second line being numbered 1 to 260, in order with the Kin Number
// There are 18 columns

$kin_num			= $kin_line_array[$this_day_kin_num][0];
$castle_num		= $kin_line_array[$this_day_kin_num][1];
$wavespell_num		= $kin_line_array[$this_day_kin_num][2];
$harmonic_num		= $kin_line_array[$this_day_kin_num][3];
$color_name		= $kin_line_array[$this_day_kin_num][4];
$tone_num			= $kin_line_array[$this_day_kin_num][5];
$tone_name		= $kin_line_array[$this_day_kin_num][6];
$tone_cr_pwr		= $kin_line_array[$this_day_kin_num][7];
$tone_action		= $kin_line_array[$this_day_kin_num][8];
$tone_func		= $kin_line_array[$this_day_kin_num][9];
$seal_num			= $kin_line_array[$this_day_kin_num][10];
$seal_name		= $kin_line_array[$this_day_kin_num][11];
$seal_action		= $kin_line_array[$this_day_kin_num][12];
$seal_cr_pwr		= $kin_line_array[$this_day_kin_num][13];
$seal_func		= $kin_line_array[$this_day_kin_num][14];
$timecell			= $kin_line_array[$this_day_kin_num][15];
$guiding_power		= $kin_line_array[$this_day_kin_num][16];
$portals			= $kin_line_array[$this_day_kin_num][17];
$polar_kin		= $kin_line_array[$this_day_kin_num][18];
$earth_family		= $kin_line_array[$this_day_kin_num][19];
$timecell_number	= $kin_line_array[$this_day_kin_num][20];

$txt_zero			= $kin_line_array[0][0];
$txt_two			= $kin_line_array[0][2];
$txt_four			= $kin_line_array[0][4];
$txt_six			= $kin_line_array[0][6];
$txt_eight		= $kin_line_array[0][8];
$txt_ten			= $kin_line_array[0][10];
$txt_twelve		= $kin_line_array[0][12];
$txt_fourteen		= $kin_line_array[0][14];
$txt_sixteen		= $kin_line_array[0][16];
$txt_eighteen		= $kin_line_array[0][18];

$txt_nineteen		= $kin_line_array[0][19];
$txt_twenty		= $kin_line_array[0][20];
$txt_twentyone		= $kin_line_array[0][21];
$txt_twentytwo		= $kin_line_array[0][22];
$txt_twwentythree	= $kin_line_array[0][23];
$txt_twwentyfour	= $kin_line_array[0][24];
$txt_twwentyfive	= $kin_line_array[0][25];

$kin_num			 = 	utf8_encode($kin_num);
$castle_num		 = 	utf8_encode($castle_num);
$wavespell_num		 = 	utf8_encode($wavespell_num);
$harmonic_num		 = 	utf8_encode($harmonic_num);
$color_name		 = 	utf8_encode($color_name);
$tone_num			 = 	utf8_encode($tone_num);
$tone_name		 = 	utf8_encode($tone_name);
$tone_cr_pwr		 = 	utf8_encode($tone_cr_pwr);
$tone_action		 = 	utf8_encode($tone_action);
$tone_func		 = 	utf8_encode($tone_func);
$seal_num			 = 	utf8_encode($seal_num);
$seal_name		 = 	utf8_encode($seal_name);
$seal_action		 = 	utf8_encode($seal_action);
$seal_cr_pwr		 = 	utf8_encode($seal_cr_pwr);
$seal_func		 = 	utf8_encode($seal_func);
$timecell			 = 	utf8_encode($timecell);
$guiding_power		 = 	utf8_encode($guiding_power);
$portals			 = 	utf8_encode($portals);
$polar_kin		 = 	utf8_encode($polar_kin);
$earth_family		 = 	utf8_encode($earth_family);
$timecell_number	 =	utf8_encode($timecell_number);

$txt_zero		=	utf8_encode($txt_zero);
$txt_two		=	utf8_encode($txt_two);
$txt_four		=	utf8_encode($txt_four);
$txt_six		=	utf8_encode($txt_six);
$txt_eight	=	utf8_encode($txt_eight);
$txt_ten		=	utf8_encode($txt_ten);
$txt_twelve	=	utf8_encode($txt_twelve);
$txt_fourteen	=	utf8_encode($txt_fourteen);
$txt_sixteen	=	utf8_encode($txt_sixteen);
$txt_eighteen	=	utf8_encode($txt_eighteen);


$txt_nineteen		=	utf8_encode($txt_nineteen); // the word: Castle:
$txt_twenty		=	utf8_encode($txt_twenty); // castle 1
$txt_twentyone		=	utf8_encode($txt_twentyone);// castle 2
$txt_twentytwo		=	utf8_encode($txt_twentytwo);// castle 3
$txt_twentythree	=	utf8_encode($txt_twentythree);// castle 4
$txt_twentyfour	=	utf8_encode($txt_twentyfour); // castle 5
$txt_twentyfive	=	utf8_encode($txt_twentyfive); // the word: Wavespell:

if ($castle_num == 1){$this_castle_affirm = "$txt_nineteen $txt_twenty";}
elseif ($castle_num == 2){$this_castle_affirm = "$txt_nineteen $txt_twentyone";}
elseif ($castle_num == 3){$this_castle_affirm = "$txt_nineteen $txt_twentytwo";}
elseif ($castle_num == 4){$this_castle_affirm = "$txt_nineteen $txt_twentythree";}
else {$this_castle_affirm = "$txt_nineteen $txt_twentyfour";}

// Get Wavespell Info

$wavespell_kin_num = tmc_kin_to_wavespell($kin_num, $tone_num);

$get_ws_color	 = $kin_line_array[$wavespell_kin_num][4]; // Blue
$get_ws_seal	 = $kin_line_array[$wavespell_kin_num][11]; // Hand
$get_ws_color	= utf8_encode($get_ws_color);
$get_ws_seal	= utf8_encode($get_ws_seal);

$this_wavespell_affirm = "$txt_twwentyfive $get_ws_color $get_ws_seal";


// Now we have all the vars from the db, so let's create our phrasses:

$affirm_one	 = "$txt_zero $tone_cr_pwr $txt_two $seal_action"; // I	tone_cr_pwr	in order to	seal_action
$affirm_two	 = "$txt_four $tone_action $txt_six $seal_cr_pwr";
$affirm_three	 = "$txt_eight $timecell $txt_ten $seal_func"; // I seal the	timecell	of	seal_func
$affirm_four	 = "$txt_twelve $tone_name $txt_fourteen $tone_func"; // With the	tone_name	tone of	tone_func
$affirm_five	 = "$txt_sixteen $guiding_power"; // Portal
$affirm_six	 = "$txt_eighteen"; // Portal

// Get guiding power seal num
$guid_pwr_seal_num = guiding_power($tone_num, $seal_num);

// Get seal graphics for this kin
$seal_image = seal_num_to_img_num($seal_num);
$tone_image = tone_num_to_img_num($tone_num);

// Translate this kin to seo
$this_day_kin_seof = tmc_translate_kin_to_seo($this_day_kin_num);

// Show Kin Images
$popup_content .= "<div style=\"float: left; text-align: center;\">";

$popup_content .= "<div class=\"tone_image\" style=\"float: left; text-align: center;\">";
$popup_content .= "<img src=\"$tones_img_dir/$tone_image\" border=0 width=60 height=35 vspace=10 alt=\"$Tone\">";
$popup_content .= "</div>\n\n";
$popup_content .= "<div class=\"proper_date\" style=\"float: left; text-align: right;\">";
$popup_content .= "$tm_date_proper";
$popup_content .= "</div>\n\n";
$popup_content .= "<div class=\"seal_image\" style=\"text-align: center;\">";
$popup_content .= "<img src=\"$seals_img_dir/$seal_image\" border=0 width=60 height=60 vspace=5 alt=\"$seal\"></a>";
$popup_content .= "</div>\n";


// Show Kin Number and Text
$popup_content .= "<div style=\"float: left; text-align: left; margin-top: 37px; margin-left: 13px;\">";
$popup_content .= "<h3>Kin $this_day_kin_num</h3>";
$popup_content .= "$color_name<br>$tone_name<br>$seal_name\n";
$popup_content .= "</div>\n";

$popup_content .= "</div>\n";

// Show affirmation for this Kin
$popup_content .= "<div style=\"text-align: center; margin-top: 13px; margin-left: 13px; float: left;\">";
$popup_content .= "$affirm_one<br>";
$popup_content .= "$affirm_two<br>";
$popup_content .= "$affirm_three<br>";
$popup_content .= "$affirm_four<br>";
$popup_content .= "$affirm_five<br>";	
$popup_content .= "$polar_kin<br>";	
$popup_content .= "</div>\n\n";


// Portal Info
if ($portals != ""){
    	$popup_content .= "<div style=\"float: left; text-align: center; margin-top: 0px;\">";
    	$popup_content .= "<div style=\"float: left;\">";
    	$popup_content .= "<img src=\"$portals_img_dir/portals_trans.gif\" border=0 width=30 height=60 alt=\"Galactic Portal Day\">";
    	$popup_content .= "</div>\n\n";
    	$popup_content .= "<div style=\"float: left; text-align: center; margin-left: 13px; width: 75px;\">";
    	$popup_content .= "$affirm_six\n\n";
    	$popup_content .= "</div>\n\n";
    	$popup_content .= "</div>\n\n";
}

// Castle Info
$popup_content .= "<div style=\"float: left; text-align: center;\">";
$popup_content .= "<div style=\"float: left; text-align: left;\">";
$popup_content .= "$this_castle_affirm";
$popup_content .= "</div>\n\n";





// Wevespell Info
$popup_content .= "<div style=\"float: left; text-align: left; \">";
$popup_content .= "$this_wavespell_affirm<br>";
$popup_content .= "</div>\n\n";

$popup_content .= "</div>\n\n";

if ($_GET[show_famous_events] == "YES"){

	$seo_sig = tmc_translate_kin_to_seo($this_day_kin_num);

// Link to SSP -- need to get options before we can display this
    	$ssp_link = "<a class=\"ssp_link\" href=\"http://spacestationplaza.com/13-moon-dreamspell-calendar/$seo_sig\" target=\"_blank\">";
    	$popup_content .= "<br clear=\"both\">\n";
    	$popup_content .= "<div style=\"float: left; text-align: left; margin-top: 13px;\">";
    	$popup_content .= $ssp_link."Famous Events on Kin $this_day_kin_num</a>";
    	$popup_content .= "</div>\n\n";
}
$popup_content .= "<br clear=\"both\">\n\n";

echo "$popup_content";

?>