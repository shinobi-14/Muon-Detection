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

To replicate or explore this project, download the repository files and open them in EasyEDA, ensuring all file paths are correctly linked
    
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
		
	4. PCBs
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
	


