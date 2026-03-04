# AQI Simple Reflex Agent
This project develops a Simple Reflex AI Agent in C that calculates the Air Quality Index (AQI) for a region using pollutant concentration data stored in a sensor file (data.txt).

Each pollutant value is converted into an AQI sub-index using the standard breakpoint interpolation formula, and the final AQI is determined by selecting the maximum sub-index.

## AI Agent Model:
- Environment--> Regional air quality
  
- Sensors--> Pollutant data file (`data.txt`)
  
- Percepts--> PM2.5, PM10, NO₂, SO₂, CO, O₃
  
- Rules--> AQI breakpoint tables
  
- Decision--> Maximum pollutant sub-index
  
- Action--> Display AQI and category
## Pollutants Considered:
-   PM2.5
-   PM10
-   NO₂
-   SO₂
-   CO
-   O₃
## AQI Method
Each pollutant value is converted into an AQI sub-index using a linear interpolation formula between two breakpoint ranges.

    I = (I_hi − I_lo) / (BP_hi − BP_lo) × (C − BP_lo) + I_lo
    
Where:
- C = pollutant concentration
- BP_lo and BP_hi = lower and upper concentration limits
- I_lo and I_hi = corresponding AQI limits

After calculating the sub-index for all pollutants,  
the final AQI is the highest sub-index value.

    AQI = max(all pollutant sub-indices)
## AQI Categories

```
  AQI Range   Category
  ----------- --------------
  0--50       Good
  51--100     Satisfactory
  101--200    Moderate
  201--300    Poor
  301--400    Very Poor
  401--500    Severe
```
## Input File Format

Create a file named **`data.txt`** in the program directory.

Example:

    PM25=120
    PM10=180
    NO2=70
    SO2=20
    CO=1.2
    O3=40

## Program Architecture
aqi_agent.c->  AQIRange struct-> AQI breakpoint tables -> calculate_subAQI() (AQI interpolation)
-> category() (AQI classification) ->read_data() (Sensor file reader) ->main() (Agent loop)
## References

UrbanEmissions AQI Methodology:
https://urbanemissions.info/wp-content/uploads/docs/SIM-46-2021.pdf
