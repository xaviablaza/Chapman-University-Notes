# Animations

android:animateLayoutChanges="true"

makes everything look awesome

## Iterate through a ViewGroup

```java
LinearLayout rootView (LinearLayout) inflater.inflate...

for (int i=0;i<rootView.getChildCount();i++)
{
    View view = rootView.getChildAt(i);
}
```

ListView Smooth Scroll

Keyboard measurements pulling up the keyboard

writing a new comment

scroll down to tell you there's more when you scroll up through comments

## Property Animation

Setting a property of an app component over a certain period of time

For example, how fast or slow the opaqueness will be of a component over a period of time

**Alpha property is transparency**

```java
ObjectAnimator spin = ObjectAnimator.ofFloat(view,"rotation",0f,1080f); // from 0 to 1080f (degrees)
spin.setDuration(2000); // 2000ms
ObjectAnimator fade = ObjectAnimator.ofFloat(v,"alpha",1f,0f); // from opaque to transparent
fade.setDuration(1000); // 1000ms
fade.setStartDelay(1000);

AnimatorSet set = new AnimatorSet();
set.playTogether(spin, fade);
set.setInterpolator(new AccelerateInterpolator());
set.start();
```

**Translation_x** stuff to move off-screen