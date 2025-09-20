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
