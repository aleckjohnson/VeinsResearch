#TraCI POI Module
#Created By : Aleck Johnson
#   Also By : Quentin Goss
#Last Modified By : Quentin Goss
#Date Last Modified: 07/24/2018
class poi:
    def __init__(self): #default constructor
        self.s_UID = ""
        self.f_CoordX = 0.00
        self.f_CoordY = 0.00
        self.f_CoordZ = 0.00
        self.n_Value = 0
        self.s_LastVehID = ""
        self.n_LastHitTime = -1
        self.n_numHits = 0 #initialize all required variables

    def __del__(self): #default deconstructor
        # We use the deconstructor to free up memory when we don't need
        # the POI node anymore
        del self.s_UID
        del self.f_CoordX
        del self.f_CoordY
        del self.f_CoordZ
        del self.n_Value
        del self.s_LastVehID
        del self.n_LastHitTime
        del self.n_numHits
        

        
#Setters/Getters Begin Below
    def getUID(self):
        return self.s_UID
    def setUID(self,s_newID):
        self.s_UID = s_newID

    def getXCoord(self):
        return self.f_CoordX
    def setXCoord(self,f_newX):
        self.f_CoordX = f_newX

    def getYCoord(self):
        return self.f_CoordY
    def setYCoord(self,f_newY):
        self.f_CoordY = f_newY

    def getZCoord(self):
        return self.f_CoordZ
    def setZCoord(self,f_newZ):
        self.f_CoordZ = f_newZ

    def getValue(self):
        return self.n_Value
    def setValue(self,n_newVal):
        self.n_Value = n_newVal

    def getLastVehID(self):
        return self.s_LastVehID
    def setLastVehID(self,n_newVehID):
        self.s_LastVehID = n_newVehID

    def getLastHitTime(self):
        return self.n_LastHitTime
    def setLastHitTime(self,n_newHitTime):
        self.n_LastHitTime = n_newHitTime

    def getHitTotal(self):
        return self.n_numHits
    def setHitTotal(self,n_newHitTotal):
        self.n_numHits = n_newHitTotal
#End of Setters/Getters

    def increaseValue(self):
        self.n_Value += 1
    def increaseValueBy(self,n_Amt):
        self.n_Value += n_Amt
    def decreaseValue(self):
        self.n_Value -= 1

    #############################
    # A vehicle tags the POI
    #
    # @param n_Step = current timestep
    # @param s_VehID = ID of the vehicle that hits the POI
    #############################
    def vehicleHit(self,n_step,s_vehID):
        #Obtain Vehicle ID
        self.s_LastVehID = s_vehID
        
        #get Current time and set to time of hit
        self.n_LastHitTime = n_step

        # The value decreases
        self.decreaseValue()
        
        self.n_numHits += 1
    # end def vehicleHit(n_Step,s_VehID):
