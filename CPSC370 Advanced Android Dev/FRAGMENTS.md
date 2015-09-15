# Fragments

Represents a portion of an Activity, whether it has a user interface or not

Activities can have multiple fragments

Each visible fragment lives inside a ViewGroup defined inside an Activity's layout as a <fragment>

A fragment is not required to be visible

Fragments are designed to be reusable in other activites

Fragments can communicate with their Activity with the getActivity() method (can always access parent activity)

## Fragment Lifecycle

onAttach() Fragment has been associated with the Activity

onCreate()
System is creating the fragment, and initalizing essential components

onCreateView()
System is attempting to draw your UI
Return a view, can be inflated from a fragment layout file, can be created programmatically, can return null if there is no desired UI

onActivityCreated() when onCreate() finishes

onResume() the gragment is visible

onStop() fragment is no longer visible

onDestroyView() UI being removed

onDetach() deassociation of fragment

## FragmentManager & FragmentTransaction

Replaces old Fragments with new Fragments