# Muon-Detection
Muon-Detection, an independent subsystem of Project STRIVE developed for the SDL Payload Challenge, serves as a payload on the sounding rocket Airavata in IREC 2025.
<div align="center">
  <img src="https://github.com/user-attachments/assets/872929f0-4386-4d19-a50f-22ae9239c387" width="65%" />
</div>

The Muon-Detection system incorporates a commercial and a student-designed 3D-printed scintillator (developed in collaboration with IIT Roorkee) to measure muon flux along the rocket's trajectory, enabling performance comparison and supporting real-time tomography simulations for potential non-destructive testing during sonic and supersonic flight.

## Detector Architecture
#### 1. Commercial Scintillator Setup
<div align="left">
  <img src="https://github.com/user-attachments/assets/6c03538a-6122-42e7-848a-6ecff6263e46" width="45%" />
</div>
    
- Scintillator: BC-408 plastic scintillator (known for its high light yield and fast decay time)
- Photo-detector: 3mm × 3mm BROADCOM's AFBR-S4N33C013  SiPM (Silicon Photomultiplier)
- Associated Electronics

#### 2. Experimental 3D Printed Scintillator
<div align="left">
  <img src="https://github.com/user-attachments/assets/f0a06983-f850-4b3b-bb88-94683e8b09ae" width="45%" />
  <img src="https://github.com/user-attachments/assets/8e265499-d01c-4787-9d98-c18ac4b51bd5" width="45%" />
</div>

- Scintillation Components: Incorporated 2,5-diphenyloxazole (PPO) and a wavelength shifter.
- Scintillator Fabrication: Used an acrylate photo-curing monomer with aromatic rings as the base matrix.
- 3D Printing Process: Added a small amount of BAPO photo-initiator, poured the mixture into the 3D-printer VAT, and printed 100 µm layers sequentially (on top of each other) to form the final structure.

## SiPM Main PCB
The SiPM PCB is designed to interface with Silicon Photomultipliers (SiPMs) for detecting scintillation events. 
<div align="center">
  <img src="https://github.com/user-attachments/assets/df9995d7-597a-487e-8034-6f9907c64b21" width="45%" />
  <img src="https://github.com/user-attachments/assets/f526b58c-e5e8-4c39-8e34-ad291e90ccf3" width="42.75%" />
</div>

SiPM output signals are typically weak, so this PCB includes a carefully designed amplifier circuit that boosts the signal strength while preserving its integrity. 

The amplifier matches the SiPM’s voltage and current characteristics, ensuring a clean, low-noise signal that maintains the peak amplitude of fast analog pulses for accurate processing by the onboard microcontroller. 

Additionally, the PCB provides stable biasing and reliable signal routing to the data acquisition system, making it a critical component of the payload’s detection and readout chain.

## Repo Structure
The PCB was designed entirely in EasyEDA. I've included the design files, 3D files, gerber, schematic, test codes, media files and testing materials.

To replicate or explore this project, download the repository files and open them in EasyEDA, ensuring all file paths are correctly linked.
    
	1. 3D_files
		a. SIPM main PCB | SIPM small PCB
			- .mtl & .obj 3D exports for 3D visualization and mechanical fit checks.
	
	2. Design_Files 
		a. SIPM main PCB | SIPM small PCB
			i. Altium_Design_files - Exports from EasyEDA for Altium compatibility.
			ii. Autorouter_files - Auto-generated routing results.
			iii. EasyEDA_Design_files - Original PCB designs.
			iv. Export_Netlist_files - Netlists for simulation and validation.
		
	3. Fabrication_files 
		a. SIPM main PCB | SIPM small PCB
			i. Gerber files - Standard files for PCB manufacturing.
			ii. BOMs.csv - List all components used in this project.
			iii. PickAndPlace.csv - Data for automated assembly.
		
	4. Schematics
		a. SIPM main PCB | SIPM small PCB
			i. schematic.pdf - Readable schematic.
			ii. schematic.svg - Scalable/vector schematic.
	
	5.  media
		a. images - Renders, test setups, and PCB visuals.
		b. testing videos - Muon-Detection tests under different conditions.
		
	6. test codes
		All the test codes used during testing.
		
	7. testing materials
		Contains test records, analysis, and performance evaluation of commercial and 3D-printed scintillators.

 ## Components Used
 - AFBR-S4N33C013 SiPM (Silicone Photomultiplier)
 - BC-408 (Plastic Scintillator)
 - 3D-printed Scintillator
 - MIC2288 (DC-DC Boost Converter @ 33V)
 - DS3231 (Real Time Clock)
 - OPA356 (Operational Amplifier)
 - XT30 (Overload connector @ 30A)
 - SD Card Reader module
 - ESP32 C3 (32bit-microcontroler)
 - HT7833 (LDO Regulator @ 3.3V) - Redundant
 - AMS1117 (LDO Regulator @ 5V) - Redundant
 - CP2102 (UART Interface)
 - TPS56321 (Switching regulator @ 3.3V | @ 5V)

## Key Takeaways
1. It is not possible to couple two scintillators together, as there will be an immense amount of light loss at the boundary. 
2. This is the same region where we require large single crystals instead of smaller crystals coupled together. 
3. The scintillator can be coupled to the SiPM using optical-grade silicone gel/glue provided by companies such as Eljen (EJ-550, EJ-552) or Epic crystals.
4. There is a degradation of the additively manufactured scintillator with time. 
5. With temperature fluctuations, the scintillator could potentially lose its scintillation effect and overall effectiveness.
6. The PCB for the payload is designed for signal integrity, but the efficient functioning of the system in the scope of sounding rocket flight might be affected by the level of EM interference in the PCB. Therefore, readings might get affected due to this.
7. The muon detection system relies on the duration during which the rocket descends. There is a potential problem where the system can work efficiently only while it is at a specific altitude for a specific period of time.
8. While testing, I noticed that for BC-408 and 8.2 mm, squiggles are fewer compared to 3.9 mm and 6.2 mm. As the width increases, properly distinct peaks can be observed, which means thicker the sample, the farther the particle can penetrate through, so more efficient production of photons.

## Reference Materials 
- [SiPM Datasheet](https://www.farnell.com/datasheets/3096135.pdf?_gl=1*1ttkvz9*_gcl_au*MTI4NTU5OTYwNS4xNzQzNzAwNDU1)
- [OPA356 Datasheet](https://www.ti.com/lit/ds/symlink/opa356.pdf?ts=1746455532552&ref_url=https%253A%252F%252Fwww.google.com%252F)
- [Peak Detection Circuit](https://www.youtube.com/watch?v=w4531AVjBYY) (Highly Recommended)
- [britishastronomical Youtube](https://www.youtube.com/watch?v=j74CbXHByrY)
- [Front-end Electronics for SiPM](https://physicsopenlab.org/2017/11/28/front-end-electronics-for-sipm/)
- [Cosmic Watch Muon-Detector](https://github.com/spenceraxani/CosmicWatch-Desktop-Muon-Detector-v2/blob/master/PCB_Files/callibration.pdf) (Highly Recommended)
- [RD-Gammaspectra](https://www.youtube.com/watch?v=t7-f01MC4a4&t=58s) (Highly Recommended)
- [Current to Voltage Converotr](https://ecstudiosystems.com/discover/textbooks/basic-electronics/operational-amplifiers/current-to-voltage-converter/)
- [Mini SIPM Driver Board](https://hackaday.io/project/188090-mini-sipm-driver-board)
- [Muon Tomography Simulation](https://github.com/dimitra97/MuonTomographySimulation)
- [ComSAD](https://ar5iv.labs.arxiv.org/html/2110.12500)
- [Data acquisition system for the readout of SiPM arrays](https://ieeexplore.ieee.org/abstract/document/6829735) (Highly Recommended)

Author: Prithvi Raj Singh (shinobi-14)


