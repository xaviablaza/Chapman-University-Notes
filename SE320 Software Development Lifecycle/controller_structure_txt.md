xaviablaza [11:22 PM]
I have a ruby mvc question I was hoping you could answer. In our app, we have 3 different user roles (rider, driver, admin). Would it make sense to just have a `PagesController` and use if statements to render specific content for that role on a particular route? Or, would an alternative be to have multiple controllers `RiderPagesController`, `DriverPagesController`, `AdminPagesController`, given that the page content is pretty distinct for each role?

or should controllers be grouped by features? `AccountsController` would be used for login/registration, `PagesController` used to display the app's pages, and `DashboardsController` which contains logic for admin dashboard components?

ramon.tayag [11:26 PM]
Hey Xavi
I’m guessing that the difference in the pages between roles would be in the template?
If so, yes just a `PagesController`. The `DashboardsController` I usually implement as a bunch of different controllers that are under the dashboard namespace
Is this Rails?


xaviablaza [11:28 PM]
We have an `index.html.erb` file that has an if statement that checks the role and displays content specific to the role
yes this is rails

ramon.tayag [11:30 PM]
Let’s see… are the pages the same format, just differing in content?
Can you give an example?

xaviablaza [11:30 PM]
well the admin would see an admin dashboard, the rider would see a map to request rides (we're making an uber-like app)

ramon.tayag [11:31 PM]
Ohh ok

xaviablaza [11:31 PM]
so not the same format

ramon.tayag [11:31 PM]
Sounds like it’ll be quite different
So I’d do a different set of controllers per role. A user gets redirected to `/rider_dashboard` (or something like that) if they’re a rider
Maybe the namespace would be `dashboard/rider`. You can have a home controller in there, that is the root of the rider namespace
```module Dashboard
  module Rider
    class HomeController < ApplicationController # or Dashboard::BaseController if you have common things you want to set on all dashboard controllers
    end
  end
end
```

xaviablaza [11:36 PM]
so in the `controllers` folder i would have a directory `dashboard/rider` which would have a `home_controller.rb` ? and same for `dashboard/driver` and `dashboard/admin`?
is my understanding correct?

ramon.tayag [11:37 PM]
yup
If the layout for the dashboard is the same, they can just all have (or inherit from a controller) a `layout: "dashboard"` (edited)

xaviablaza [11:38 PM]
the home controller for a rider, controls what is shown on `localhost:port/rider_dashboard` ?

ramon.tayag [11:39 PM]
well if you want the url to be `/dashboard/rider` you’ll do:

```namespace :dashboard do
  namespace :rider do
    get "/" => "home#index"
  end
end
```

(something like this)

xaviablaza [11:44 PM]
hmm so if i used the code you just posted, in `views/home/index.html.erb` you would still need to check the role using if statements right? (edited)

ramon.tayag [11:44 PM]
it would be in `views/dashboard/rider/home/index.html.erb`

xaviablaza [11:45 PM]
ah ok this was what i was looking for
so each role would have its own template

ramon.tayag [11:45 PM]
Yup

xaviablaza [11:45 PM]
ok makes sense now

ramon.tayag [11:45 PM]
For anything shared, you can use partials. There are more advanced stuff like cells, but that’s fine. Keep it simple for now.
tip: for partials, pass everything in as locals. don’t assume the `@var` exists in the context (edited)

xaviablaza [11:50 PM]
ok! thank you!

ramon.tayag [11:52 PM]
np!

xaviablaza [12:06 AM]
another question. so after the rider logs in, they will be redirected to `/dashboard/rider`. is it possible for the user to just go to `localhost:port` and proxy `/dashboard/rider` ? so that the URL they see in the browser is just the root of the website?

ramon.tayag [12:08 AM]
Hmm… yes, controller at the root would just render another controller’s action
But I don’t recommend it — same URLs will show different things (edited)
If it’s because it’s long, you can make the URL `/d/rider`


xaviablaza [12:11 AM]
i was just thinking of it like facebook, if you're logged out, the root will show you a login page, but if you're logged in, the root will show you the newsfeed. not like you have to go to `/newsfeed` to view newsfeed
so different routes per page is a rails thing?

ramon.tayag [12:12 AM]
No, you can do it the way you want. It just adds more complexity
An action can render another controller’s action, but you would need to load the variables in the action
So if you have 3 things you might show, you have to load all the `@var`s there for the 3 scenarios
Howcome you want to do it this way? (edited)

xaviablaza [12:15 AM]
i just dont want to go to `localhost:port/dashboard/rider`
if it's too complex i'll just do a redirect
just a nice to have thing

ramon.tayag [12:15 AM]
Oh, yes, redirect from sign in
It’s not “too complex” — I just try to be relentless removing with the magic stuff
if you use devise, there’s a method like `after_sign_in_path_for(user)` method in the controller. if `current_user.role == "rider"; redirect_to dashboard_rider_path; ...`
or better yet `polymorphic_path([:dashboard, user.role])`

xaviablaza [12:28 AM]
yeah our team is using devise
i'm having trouble understanding what you just said because another person in my team coded the login

ramon.tayag [12:29 AM]
Here you go: https://github.com/plataformatec/devise/wiki/How-To:-redirect-to-a-specific-page-on-successful-sign-in
