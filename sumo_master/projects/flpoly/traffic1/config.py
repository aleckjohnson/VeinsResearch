import os
###############################
#      Runner.py Configuration
###############################
s_absolute_path = os.path.dirname(os.path.abspath(__file__))
s_sumo_tools_dir = "/home/veins/src/sumo-0.30.0/tools"
s_route_file = s_absolute_path + "/../data/Version2/flpoly.rou.xml"
is_geo = False
if is_geo:
  s_sumocfg_file = s_absolute_path + "/../data/Version2/flpoly_geo.sumocfg"
else:
  s_sumocfg_file = s_absolute_path + "/../data/Version2/flpoly.sumocfg"
n_time_steps = 30000

# The properties of our vehicles
s_vtype_passenger = """<vType id="chevy_s10" accel="0.6" decel="1.3" sigma="0.4" length="5" minGap="2.5" maxSpeed="3" guiShape="passenger"/>"""
s_vtype_pedestrian = """<vType id="bob" accel="1.5" decel="2" signma="0.4" length="0.215" minGap="0.25" maxSpeed="5.4" guiShape="pedestrian" />"""

# How many time steps between new vehicles spawning?
n_vehicle_spawn_rate=15
n_vehicles_max=300

# Random Seed
n_seed=773

# Routes
cw_route = ['505127440#0', '372651351#1', '370373777#0', '370373777#1', '370373777#2', '370373777#3', '370373777#4', '481476622#0', '481476622#1', '370373774', '481476640#0', '481476640#1', '370373770', '370373771#0', '370373771#1', '370373771#2', '370373765#0', '370373765#3', '370373765#4', '481476641#0', '481476641#1', '372651340', '481476631#0', '481476631#1', '370373767#0', '372651350#1', '-505127440#0']

ccw_route = ['279425010#2', '370373762#2', '372651341#0', '481476642#0', '481476642#1', '370373769#0', '370373769#1', '370373769#2', '370373769#5', '370373769#6', '370373769#7', '372651352', '370373773', '372651356', '370373775#0', '370373775#1', '370373776#0', '370373776#1', '370373776#2', '370373776#3', '370373776#4', '370373776#5', '370373768#2', '370373768#3', '370373768#4', '370373763#0', '370373763#1', '372651339#0', '372651339#1', '279425015#2']
