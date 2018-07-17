#TraCI POI Module
#Created By : Aleck Johnson
#Last Modified By : Aleck Johnson
#Date Last Modified: 07/16/2018

class poi:
    def __init__(self): #default constructor
        s_UID = ""
        f_CoordX = 0.00
        f_CoordY = 0.00
        f_CoordZ = 0.00
        n_Value = 0
        s_AccidentID = ""
        t_PrevHitTime = 0
        t_newTimeOfHit = 0
        n_numHits = 0 #initialize all required variables

    def __del__(self): #default deconstructor
        # We use the deconstructor to free up memory when we don't need
        # the POI node anymore
        del s_UID
        del f_CoordX
        del f_CoordY
        del f_CoordZ
        del n_Value
        del s_AccidentID
        del t_PrevHitTime
        del t_newTimeOfHit
        del n_numHits
        

        
#Setters/Getters Begin Below
    def getUID():
        return s_UID
    def setUID(newID):
        s_UID = newID

    def getXCoord():
        return f_CoordX
    def setXCoord(newX):
        f_CoordX = newX

    def getYCoord():
        return f_CoordY
    def setYCoord(newY):
        f_CoordY = newY

    def getZCoord():
        return f_CoordZ
    def setZCoord(newZ):
        f_CoordZ = newZ

    def getValue():
        return n_Value
    def setValue(newVal):
        n_Value = newVal

    def getAccidentID():
        return s_AccidentID
    def setAccidentID(newAccidentID):
        s_AccidentID = newAccidentID

    def getLastHitTime():
        return t_PrevHitTime
    def setLastHitTime(newHitTime):
        t_PrevHitTime = newHitTime

    def getHitTotal():
        return n_numHits
    def setHitTotal(currentHits):
        n_numHits = currentHits
#End of Setters/Getters
    def increaseValue():
        n_Value += 1
    def decreaseValue():
        n_Value -= 1

    def accidentOccur():
        #how do we get a current hitID and Time from the simulator?
        #Obtain Vehicle ID
        setAccidentID(hitID)
        #get Current time and set to time of hit
        setLastHitTime(CurrentTime)
        n_Value -=1
