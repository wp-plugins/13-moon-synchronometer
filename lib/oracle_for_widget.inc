<?php // cal_show_kin_info.inc CALLED BY: 

// This file is used if the kin only view is used for the widget or shortcode

// By the time we get to this file, we have quite a bit.


// In pre_for_kin.inc  we use another name
$tribe_num = $seal_num;

// Name the Kin
$KN_Tribe_Name = $kin_line_array["$tribe_num"]["11"];

// ------------------- Get Guiding Power -------------------------
$Guid_pwr_tribe_num = guiding_power($tone_num, $tribe_num);
$Guid_pwr_tribe_num_for_img = $Guid_pwr_tribe_num;
if (strlen($Guid_pwr_tribe_num_for_img) < 2){$Guid_pwr_tribe_num_for_img = '0'.$Guid_pwr_tribe_num_for_img;}
$GP_Tribe_Name = $kin_line_array["$Guid_pwr_tribe_num"]["11"];

// Figure antipode
$Antipode_tribe_num = ($tribe_num + 10);
$Antipode_tribe_num = abs($Antipode_tribe_num);  // $abs3 = 5; (integer)
if ($Antipode_tribe_num > 20){$Antipode_tribe_num = ($Antipode_tribe_num - 20);}
$Antipode_tribe_num_for_img = $Antipode_tribe_num;
if (strlen($Antipode_tribe_num_for_img) < 2){$Antipode_tribe_num_for_img = '0'.$Antipode_tribe_num_for_img;}
$AP_Tribe_Name = $kin_line_array["$Antipode_tribe_num"]["11"];

// Figure Analog users tribe + analog_tribe = 19
$Analog_tribe_num = ($tribe_num - 19);
if ($tribe_num == 20){$Analog_tribe_num = 19;}
if ($Analog_tribe_num == 0){$Analog_tribe_num = 20;}
$Analog_tribe_num = abs($Analog_tribe_num);  // $abs3 = 5; (integer)
$Analog_tribe_num_for_img = $Analog_tribe_num;
if (strlen($Analog_tribe_num_for_img) < 2){$Analog_tribe_num_for_img = '0'.$Analog_tribe_num_for_img;}

$AL_Tribe_Name = $kin_line_array[$Analog_tribe_num][11];

// Figure Occult users tribe + occult_tribe = 21
$Occult_tribe_num = ($tribe_num - 21);
$Occult_tribe_num = abs($Occult_tribe_num);
$Occult_tribe_num_for_img = $Occult_tribe_num;
if (strlen($Occult_tribe_num_for_img) < 2){$Occult_tribe_num_for_img = '0'.$Occult_tribe_num_for_img;}
$OC_Tribe_Name = $kin_line_array["$Occult_tribe_num"]["11"];

// Build contents of each cell

// Assign Various Images

// TONES
$KN_Tone_Image = '<img src="'.$top_tones_img_dir.'/'.$tone_image.'" alt="This Kin Tone" title="This Kin Tony">';
$OC_Tone_Image = '<img src="'.$top_tones_img_dir.'/'.$tone_image.'.png" alt="This Kin Tone" title="This Kin Tone">';

// TRIBES OR SEALS
$KN_Tribe_Image = '<img src="'.$seals_img_dir.'/'.$seal_image.'" alt="This Kin Seal" title="'.$KN_Tribe_Name.'" class="this_kin_class">';
$GP_Tribe_Image = '<img src="'.$seals_img_dir.'/'.$Guid_pwr_tribe_num_for_img.'.png" alt="This Kin Seal" title="'.$GP_Tribe_Name.'">';
$AP_Tribe_Image = '<img src="'.$seals_img_dir.'/'.$Antipode_tribe_num_for_img.'.png" alt="This Kin Seal" title="This Kin Seal">';
$AL_Tribe_Image = '<img src="'.$seals_img_dir.'/'.$Analog_tribe_num_for_img.'.png" alt="This Kin Seal" title="This Kin Seal">';
$OC_Tribe_Image = '<img src="'.$seals_img_dir.'/'.$Occult_tribe_num_for_img.'.png" alt="This Kin Seal" title="This Kin Seal">';

$KN_PKG = '<div class="main_kin_tainer" id="main_kin">';
$KN_PKG .= '<div class="otone_kin_image">'.$KN_Tone_Image.'</div>';
$KN_PKG .= '<div class="oseal_kin_image">'.$KN_Tribe_Image.'</div>';
$KN_PKG .= '<div class="oracle_word">'.$KN_Tribe_Name.'</div>';
$KN_PKG .= '</div>';

$GP_PKG = '<div class="orkin_tainer">';
$GP_PKG .= '<div class="oracle_word">'.$word_guiding_power.'</div>';
$GP_PKG .= '<div class="oseal_image">'.$GP_Tribe_Image.'</div>';
$GP_PKG .= '<div class="oracle_word">'.$GP_Tribe_Name.'</div>';
$GP_PKG .= '</div>';

$AP_PKG = '<div class="orkin_tainer">';
$AP_PKG .= '<div class="oracle_word">'.$word_antipode.'</div>';
$AP_PKG .= '<div class="oseal_image">'.$AP_Tribe_Image.'</div>';
$AP_PKG .= '<div class="oracle_word">'.$AP_Tribe_Name.'</div>';
$AP_PKG .= '</div>';

$AL_PKG = '<div class="orkin_tainer">';
$AL_PKG .= '<div class="oracle_word">'.$word_analog.'</div>';
$AL_PKG .= '<div class="oseal_image">'.$AL_Tribe_Image.'</div>';
$AL_PKG .= '<div class="oracle_word">'.$AL_Tribe_Name.'</div>';
$AL_PKG .= '</div>';

$OC_PKG = '<div class="orkin_tainer">';
$OC_PKG .= '<div class="oracle_word">'.$word_occult.'</div>';
$OC_PKG .= '<div class="oseal_image">'.$OC_Tribe_Image.'</div>';
$OC_PKG .= '<div class="oracle_word">'.$OC_Tribe_Name.'</div>';
$OC_PKG .= '</div>';

// Start Pop Content
$ocx = "";

// Wrapper
$ocx .= "<div class=\"oracle_tainer\" id=\"oracle_tainer_id\">"; // One Divs to wrap EVERYTHING
$ocx .= "<div class=\"oracle_content_toggle_div\">";  // Another DIV  is the toggle content

// Diusplay Destiny Pattern
$ocx .=  "<div class=\"destiny_pattern_class\" id=\"oracle_div\">"; // div to wrap table

// -------------- Table for five kin
$ocx .=  "<table cellpadding=0 cellspacing=0>\n";

// Guiding Power Row
$ocx .=  '<tr>';
$ocx .=  '<td></td>';
$ocx .= '<td>'.$GP_PKG.'</td>';
$ocx .=  "<td></td>";
$ocx .=  "</tr>\n";

// Antipode
$ocx .=  "<tr>\n";
$ocx .= '<td>'.$AP_PKG.'</td>';
// This Kin
$ocx .= '<td>'.$KN_PKG.'</td>';
// Analog Pwr
$ocx .= '<td>'.$AL_PKG.'</td>';
$ocx .=  "</tr>\n";

// Occult Power Row
$ocx .=  "<tr>\n";
$ocx .=  "<td></td>";
$ocx .= '<td style="padding-top: 10px;">'.$OC_PKG.'</td>';
$ocx .=  "<td></td>";
$ocx .=  "</tr>\n";

$ocx .=  "</table>\n"; // end table
$ocx .=  "</div>\n"; // end Div that wraps table
$ocx .= "</div>\n";  // end DIV  is the toggle content


// FOR WIDGET ONLY Set the starting visibility of the main section
if (isset($this_instance_settings['display_onload'])) {
	$display_onload = $this_instance_settings['display_onload'];
	if ($display_onload === "on") {$start_display = 'block';} else {$start_display = 'none';}
} else {$start_display = 'none';}

// Wrap the whole thing in a disappearing div
$ocx .= "<div class=\"toggled_oracle_content\" style=\"display: $start_display; clear: both;\">";

// Show a header
$ocx .= '<div class="oracle_header_txt">';
$ocx .= 'Oracle of Destiny';
$ocx .= '</div>';

// Show Kin Number and Text
$ocx .= "<div class=\"kinfo_tainer\">";
$ocx .= "<div class=\"color_tone_tribe\">$color_name $tone_name $seal_name</div>\n";
$ocx .= "</div>\n";

$ocx .= "<div class=\"timewatch_tainer\">";
$ocx .= '<img src="'.$img_dir.'/timewatch.png" style"width: 100%;">';
$ocx .= "</div>\n";

$ocx .= "</div>\n\n"; // END disappearing div

$ocx .= "</div>\n";  // END DIV  is the ENTIRE content

echo "$ocx";

?>