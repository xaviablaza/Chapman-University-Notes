# User Interfaces

`dp` density independent pixels

1dp is 1/160th of an inch on a device's screen

`sp` scale-independent pixels

Density-independent, but also take device font size preference into consideration

Typically used for text

UI Test Fragment

## Styles

Can apply colors to a theme (only works with API above 20)

```xml
<style name="AppTheme" parent="android:Theme.Material.Light">
  <item name="android:colorPrimary">@color/soothing_blue</item>
  <item name="android:colorPrimaryDark">@color/dark_blue</item>
  <item name="android:colorAccent">@color/base_gray</item>
```

Background of the shape (circle button)

### State List Drawable

Different background for when it's pressed than when it is normal
- Using a <selector> tag with different drawable <item> children with specified states

### Layer List Drawable

- Allow for combination of two XML drawables in one
- Using a <layer-list> tag with drawable <item> children

### AnimationUtils Class

`Animation slideOutAnim = AnimationUtils.loadAnimation(getActivity(), android.R.anim.slide_out_right)`

Animation callbacks