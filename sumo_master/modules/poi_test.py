# Put the code used for testing poi.py here
# Import module
import poi
print("poi module sucessfully imported.")

# Initialize class
poi_test = poi.poi()
print("poi_test initializes as object poi.")

# UID
print()
print("UID="+poi_test.getUID())
poi_test.setUID("Fuzzy Bunny")
print("UID="+poi_test.getUID())

# XYZ Coordinates
print()
print("X="+str(poi_test.getXCoord()))
poi_test.setXCoord(50.00)
print("X="+str(poi_test.getXCoord()))
print("Y="+str(poi_test.getYCoord()))
poi_test.setYCoord(133.00)
print("Y="+str(poi_test.getYCoord()))
print("Z="+str(poi_test.getZCoord()))
poi_test.setZCoord(74.00)
print("Z="+str(poi_test.getYCoord()))

# Vehicle Hit Info
print()
print("LastVehID="+poi_test.getLastVehID())
poi_test.setLastVehID("Veh77")
print("LastVehID="+poi_test.getLastVehID())
print("LastHitTime="+str(poi_test.getLastHitTime()))
poi_test.setLastHitTime(1337)
print("LastHitTime="+str(poi_test.getLastHitTime()))
print("HitTotal="+str(poi_test.getHitTotal()))
poi_test.setHitTotal(12)
print("HitTotal="+str(poi_test.getHitTotal()))

# Value operations
print()
print("value="+str(poi_test.getValue()))
poi_test.setValue(300)
print("value="+str(poi_test.getValue()))
poi_test.increaseValue()
print("value="+str(poi_test.getValue()))
poi_test.increaseValueBy(-50)
print("value="+str(poi_test.getValue()))
poi_test.decreaseValue()
print("value="+str(poi_test.getValue()))

# Vehicle Hit
print()
poi_test.setLastVehID("")
print("LastVehID="+poi_test.getLastVehID())
poi_test.setLastHitTime(-1)
print("LastHitTime="+str(poi_test.getLastHitTime()))
poi_test.setValue(0)
print("value="+str(poi_test.getValue()))
poi_test.vehicleHit(400,"Veh456")
print("LastVehID="+poi_test.getLastVehID())
print("LastHitTime="+str(poi_test.getLastHitTime()))
print("value="+str(poi_test.getValue()))

# Delete
print()
del poi_test
try:
  print(poi_test.getUID())
except:
  print("poi_test sucessfully deleted")

