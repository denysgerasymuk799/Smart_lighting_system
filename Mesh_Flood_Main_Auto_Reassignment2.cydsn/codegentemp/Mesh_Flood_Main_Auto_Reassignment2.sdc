# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\ucu\2_course1_term\POC\programs\my_works\Smart_lightning_system\Mesh_Flood_Main_Auto_Reassignment2.cydsn\Mesh_Flood_Main_Auto_Reassignment2.cyprj
# Date: Sat, 16 Jan 2021 16:06:36 GMT
#set_units -time ns
create_clock -name {UART_SCBCLK(FFB)} -period 1458.3333333333333 -waveform {0 729.166666666667} [list [get_pins {ClockBlock/ff_div_1}]]
create_clock -name {Clock_Heart_beat(FFB)} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {Clock_Waiting_Time(FFB)} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ff_div_8}]]
create_clock -name {Clock_Timer_Change_Color(FFB)} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ff_div_9}]]
create_clock -name {Timer_Is_Free_Clock(FFB)} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ff_div_10}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyWCO} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/wco}]]
create_clock -name {CyLFCLK} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyECO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/eco}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {UART_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 35 71} [list]
create_generated_clock -name {PrISM_Clock} -source [get_pins {ClockBlock/hfclk}] -edges {1 241 481} [list [get_pins {ClockBlock/udb_div_0}]]
create_generated_clock -name {Clock_Heart_beat} -source [get_pins {ClockBlock/hfclk}] -edges {1 24001 48001} [list]
create_generated_clock -name {Clock_Waiting_Time} -source [get_pins {ClockBlock/hfclk}] -edges {1 24001 48001} [list]
create_generated_clock -name {Clock_Timer_Change_Color} -source [get_pins {ClockBlock/hfclk}] -edges {1 24001 48001} [list]
create_generated_clock -name {Timer_Is_Free_Clock} -source [get_pins {ClockBlock/hfclk}] -edges {1 24001 48001} [list]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for D:\ucu\2_course1_term\POC\programs\my_works\Smart_lightning_system\Mesh_Flood_Main_Auto_Reassignment2.cydsn\TopDesign\TopDesign.cysch
# Project: D:\ucu\2_course1_term\POC\programs\my_works\Smart_lightning_system\Mesh_Flood_Main_Auto_Reassignment2.cydsn\Mesh_Flood_Main_Auto_Reassignment2.cyprj
# Date: Sat, 16 Jan 2021 16:06:33 GMT
