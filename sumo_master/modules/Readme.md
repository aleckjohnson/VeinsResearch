# <a name="top_of_page"></a>modules
>Quentin: This section contains notes about the various python modules we created.
>
>[Sumo + TraCI Home](../Readme.md)

---

## <a name="poi"></a>Point of Interest
[Top](#top_of_page)

A class created to manage Point of Interest (POI) nodes featuring coordinates, values, increase/decrease and vehicle hit methods.
Useful code:
```
# Importing the POI library
import poi

# Initializing a default POI object
o_poi = poi.poi()

# Initializing a POI object with parameters
# closest_edge = (edge_ID,x,y)
# poi.poi(id,x,y,value,closest_edge)
o_poi = poi.poi("veh0",30.0,25.0,50,("gneE15",15.4,10.3))
```
