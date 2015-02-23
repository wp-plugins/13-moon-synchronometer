<?php

function tmc_admin_options_menu() {
	//create new top-level menu
	add_options_page('13-Moon Calendar', '13-Moon Calendar', 'administrator', __FILE__, 'thirteen_moon_settings_page');
	add_action( 'admin_init', 'thirteen_moon_calendar_register_mysettings' );
}

function thirteen_moon_calendar_register_mysettings() {
	//register our settings
	register_setting( 'tmc-settings-group', 'decode_table_background_color' );
	register_setting( 'tmc-settings-group', 'moon_table_background_color' );
	register_setting( 'tmc-settings-group', 'plasma_table_background_color' );
	register_setting( 'tmc-settings-group', 'day_with_posts_highlight_border_color' ); // NEW
	register_setting( 'tmc-settings-group', 'show_num_posts' ); // NEW
	register_setting( 'tmc-settings-group', 'show_famous_events' ); // NEW
	register_setting( 'tmc-settings-group', 'curr_day_hilite_color' ); // NEW
	register_setting( 'tmc-settings-group', 'permit_credits' );
	register_setting( 'tmc-settings-group', 'last_save_time' );
}

// Don't add anymore functions:

function thirteen_moon_settings_page() {
?>
<div class="wrap">
<h2>13-Moon Synchronometer (calendar) Settings</h2>


<?php


if ($_GET["settings-updated"] === "true"){
	$table_bg = "#AEA";
} else {
	$table_bg = "";
}

$curr_date = date("D F j, Y g:i:s a  ");
$save_time_mess = get_option('last_save_time');

echo "<table bgcolor=$table_bg>\n";
if ($_GET["settings-updated"] === "true"){
	echo "<tr><th colspan=2><h2>Settings Saved!</h2></th><tr>\n";
}
echo "<tr><td>Current Date:</td><td>$curr_date</td></tr>\n";
echo "<tr><td>Last Save:</td><td>$save_time_mess</td></tr>\n";
echo "</table>\n";
?>

<hr>

<form method="post" action="options.php">
    <?php settings_fields( 'tmc-settings-group' ); ?>

    <table class="form-table">

	   <tr>
	   <th scope="row" style="width: 400px;"><b>Decoder Table Background Color:</b>
<br> (default: eee) A hex value is either 3 or 6 characters.  For instance FF0000 is the same as F00 or another way to say red.  Each digit can be 0-8 or A-F.  000 is black.  FFF is white.  Each place stands for RED, GREEN, and BLUE.  So blue is 00F.  Grey is any value of the same number/letter.  For instance, ddd is a darker grey than eee.</th>
	   <td valign=top>
#<input size=8 maxlength=6 type="text" name="decode_table_background_color" value="<?php echo get_option('decode_table_background_color'); ?>" /> -- hex value
		</td>
	   </tr>

	   <tr>
	   <th scope="row"><b>Moon Table Background Color:</b><br>(default: ddd)</th>
	   <td valign=top>
#<input size=8 maxlength=6 type="text" name="moon_table_background_color" value="<?php echo get_option('moon_table_background_color'); ?>" /> Any hex Value
		</td>
	   </tr>

	   <tr>
	   <th scope="row"><b>Plasma Table Background Color:</b><br>(default: fff - white)</th>
	   <td valign=top>
#<input size=8 maxlength=6 type="text" name="plasma_table_background_color" value="<?php echo get_option('plasma_table_background_color'); ?>" />Any hex Value
		</td>
	   </tr>



	   <tr>
	   <th scope="row"><b>Current Day Highlight Color</b></th>
	   <td valign=top>
<input size=8 maxlength=6 type="text" name="curr_day_hilite_color" value="<?php echo get_option('curr_day_hilite_color'); ?>" />px (Default is 00f)
		</td>
	   </tr>

	   <tr>
	   <th scope="row"><b>Day With Posts Button Text and Border Color</b></th>
	   <td valign=top>
<input size=8 maxlength=6 type="text" name="day_with_posts_highlight_border_color" value="<?php echo get_option('day_with_posts_highlight_border_color'); ?>" />hex (Default is f4f)
		</td>
	   </tr>

	   <tr>
	   <th scope="row"><b>Maximum Number of Posts shown in Day Popup</b></th>
	   <td valign=top>
<input size=8 maxlength=2 type="text" name="show_num_posts" value="<?php echo get_option('show_num_posts'); ?>" />(Default is 5)
		</td>
	   </tr>


		<?php $show_famous_events = get_option('show_famous_events'); ?>
		<?php if ($show_famous_events !== "YES"){$show_famous_events = "NO";} ?>

	   <tr>
	   <th scope="row"><b>Show Famous Events Link</b></th>
	   	<td>
		<input type=radio name="show_famous_events" value="YES" <?php if ($show_famous_events === "YES"){echo " CHECKED";} ?> /> Yes
		<input type=radio name="show_famous_events" value="NO" <?php if ($show_famous_events === "NO"){echo " CHECKED";} ?> /> No
		</td>
	   </tr>

		<?php $permit_credits = get_option('permit_credits'); ?>
		<?php if (!isset($permit_credits)){$permit_credits = "YES";} ?>

	   <tr>
	   <th scope="row"><b>Show Credits</b></th>
	   	<td>
		<input type=radio name="permit_credits" value="YES" <?php if ($permit_credits === "YES"){echo " CHECKED";} ?> /> Yes
		<input type=radio name="permit_credits" value="NO" <?php if ($permit_credits === "NO"){echo " CHECKED";} ?> /> No
		</td>
	   </tr>

    </table>
    
    <p class="submit">
	<input type="hidden" name="last_save_time" value="<?php echo $curr_date; ?>" />
<br>
    <input type="submit" class="button-primary" value="<?php _e('Save Changes') ?>" />
    </p>

</form>

<hr>
<h2>What do you want in this plugin?</h2>
We're wondering what OTHER settings or FEATURES you might like.
<br><br>
With the next version, we hope to have:
<ul>
<li>- Color of text on day button with posts</li>
<li>- Position (top or bottom) of the day's posts appearing in the popup dialog</li>
<li>- Translate: English to Dutch and Spanish - it will sense user's language and switch on its own</li>

<li>- List most recent activity (BuddyPress)</li>
<li>- List users born on this kin (BuddyPress-friendly)</li>

</ul>
Please rate this plugin, and share know how it looks in YOUR copy of WordPress.
<br><br>If you like this plugin, you might also like the <a href="http://wordpress.org/plugins/cosmic-history-quotes/" target="_blank">Cosmic History Quotes WP Plugin</a>

<hr>


	<h2>Inspiration and Support</h2>
	<li><a class=credits href="http://lawoftime.org/" title="Foundation for the Law of Time">Foundation for the Law of Time (FLT)</a></li>
	<li><a class=credits href="http://planetartnetwork.info/" title="Planet Art Network">Planet Art Network (PAN)</a></li>
	<li><a class=credits href="http://spacestationplaza.com/" title="Space Station Plaza Galactic Portal">Space Station Plaza (SSP)</a></li>
	<li><a class=credits href="http://anthonyfogleman.com/blog/wordpress-plugins/" title="Plugin author: Anthony Fogleman (Anka) Kin 139 Solar Storm">Plugins by Anka (kin 139)</a></li>
	<li><a class=credits href="http://www.wetvantijd.nl" title="Dutch translation: Juryt Abma Kin-243 Solar Night">Developed for the Dutch Law of Time website</a></li>
	<li><a class=credits href="http://u-ching.com" title="uCHING - Juryt Abma Kin-243 Solar Night">Developed also for u-Ching.com</a></li>

</div>
<?php } ?>