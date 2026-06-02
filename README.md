# Software for CaryFTIR 630
This project is the Bachelor project of five students at Uppsala University. This code acts as third-party library for the CaryFTIR 630 spectrometer. The purpose for this project was to allow for the Department of Chemistry at Uppsala University to automate the workflow and create a platform independant library for the machine.

# How to use
1. (Optional) Create settings
If you wish to add custom settings, create an instance of the Settings class (from classes.py)
2. Create an instance of the CaryFTIR class

    ```driver = CaryFTIR()```

    Or in case you have created custom settings:

    ```driver = CaryFTIR(settings=settings)```
3. Call the boot function
    ```driver.boot()```
4. Start measurement loop
    ```driver.measurment_loop()```
5. Plot the spectrum`
    ```driver.plot_spectrum()```


The main function in the CaryFTIR.py file has en example on how to use the library.

