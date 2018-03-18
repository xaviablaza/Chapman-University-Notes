// Generates the default radius for PSAFE to pick up
function generateDefaultRadius(map) {
var rectangle;
// These are the bounds around the university that PSAFE has given us
var bounds = {
          north: 33.805033545182255,
          south: 33.776082751851,
          east: -117.83182508881,
          west: -117.8779956515
        };
        // Define the rectangle and set its editable property to true.
        rectangle = new google.maps.Rectangle({
          bounds: bounds,
          editable: true,
          draggable: false
        });
  rectangle.setMap(map);
}

// Night mode feature
function nightMode(time, theMap) {
  // If the time is around 6PM change to Night Mode
  if (time >= 18 || time <= 7) { 
          // Styles a map in night mode.
         theMap = new google.maps.Map(document.getElementById('map'), {
           center: {lat: 33.793348, lng: -117.851350},
           zoom: 13,
           styles: [
             {elementType: 'geometry', stylers: [{color: '#242f3e'}]},
             {elementType: 'labels.text.stroke', stylers: [{color: '#242f3e'}]},
             {elementType: 'labels.text.fill', stylers: [{color: '#746855'}]},
             {
               featureType: 'administrative.locality',
               elementType: 'labels.text.fill',
               stylers: [{color: '#d59563'}]
             },
             {
               featureType: 'poi',
               elementType: 'labels.text.fill',
               stylers: [{color: '#d59563'}]
             },
             {
               featureType: 'poi.park',
               elementType: 'geometry',
               stylers: [{color: '#263c3f'}]
             },
             {
               featureType: 'poi.park',
               elementType: 'labels.text.fill',
               stylers: [{color: '#6b9a76'}]
             },
             {
               featureType: 'road',
               elementType: 'geometry',
               stylers: [{color: '#38414e'}]
             },
             {
               featureType: 'road',
               elementType: 'geometry.stroke',
               stylers: [{color: '#212a37'}]
             },
             {
               featureType: 'road',
               elementType: 'labels.text.fill',
               stylers: [{color: '#9ca5b3'}]
             },
             {
               featureType: 'road.highway',
               elementType: 'geometry',
               stylers: [{color: '#746855'}]
             },
             {
               featureType: 'road.highway',
               elementType: 'geometry.stroke',
               stylers: [{color: '#1f2835'}]
             },
             {
               featureType: 'road.highway',
               elementType: 'labels.text.fill',
               stylers: [{color: '#f3d19c'}]
             },
             {
               featureType: 'transit',
               elementType: 'geometry',
               stylers: [{color: '#2f3948'}]
             },
             {
               featureType: 'transit.station',
               elementType: 'labels.text.fill',
               stylers: [{color: '#d59563'}]
             },
             {
               featureType: 'water',
               elementType: 'geometry',
               stylers: [{color: '#17263c'}]
             },
             {
               featureType: 'water',
               elementType: 'labels.text.fill',
               stylers: [{color: '#515c6d'}]
             },
             {
               featureType: 'water',
               elementType: 'labels.text.stroke',
               stylers: [{color: '#17263c'}]
             }
           ]
         });

       } else {
         theMap = theMap;
      }

    generateDefaultRadius(theMap);
    return theMap;
}
