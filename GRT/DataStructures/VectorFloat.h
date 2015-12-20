/*
GRT MIT License
Copyright (c) <2012> <Nicholas Gillian, Media Lab, MIT>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial 
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT 
LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef GRT_VECTOR_FLOAT_HEADER
#define GRT_VECTOR_FLOAT_HEADER

#include "GRT/Util/GRTTypedefs.h"
#include "Vector.h"
#include "../Util/MinMax.h"
#include "../Util/DebugLog.h"
#include "../Util/ErrorLog.h"
#include "../Util/WarningLog.h"

GRT_BEGIN_NAMESPACE

class VectorFloat : public Vector< float_t >{
public:
    /**
     Default Constructor
     */
    VectorFloat();
    
    /**
     Constructor, sets the size of the vector
     
     @param size: sets the size of the vector
     */
    VectorFloat( const unsigned int size );

    /**
     Constructor, sets the size of the vector and sets all elements to value
     
     @param size: sets the size of the vector
     @param value: the value that will be written to all elements in the vector
     */
    VectorFloat( const unsigned int size, const float_t &value );
    
    /**
     Copy Constructor, copies the values from the rhs VectorFloat to this VectorFloat instance
     
     @param rhs: the VectorFloat from which the values will be copied
     */
    VectorFloat(const VectorFloat &rhs);
    
    /**
     Destructor, cleans up any memory
     */
    virtual ~VectorFloat();
    
    /**
     Defines how the data from the rhs VectorFloat should be copied to this VectorFloat
     
     @param rhs: another instance of a VectorFloat
     @return returns a reference to this instance of the VectorFloat
     */
    VectorFloat& operator=(const VectorFloat &rhs);
    
    /**
     Defines how the data from the rhs Vector< float_t > should be copied to this VectorFloat
     
     @param rhs: an instance of a Vector< float_t >
     @return returns a reference to this instance of the VectorFloat
     */
    VectorFloat& operator=(const Vector< float_t > &rhs);
    
    /**
     Defines how the data from the rhs vector of VectorFloats should be copied to this VectorFloat
     
     @param rhs: a vector of VectorFloats
     @return returns a reference to this instance of the VectorFloat
     */
    VectorFloat& operator=(const vector< VectorFloat > &rhs);
    
    /**
     Resizes the VectorFloat to the new size of [rows cols]
     
     @param rows: the number of rows, must be greater than zero
     @param cols: the number of columns, must be greater than zero
     @return returns true or false, indicating if the resize was successful
     */
    //virtual bool resize(const unsigned int rows,const unsigned int cols);
    
    /**
     Saves the vector to a CSV file.  This replaces the deprecated saveToCSVFile function.
     
     @param filename: the name of the CSV file
     @return returns true or false, indicating if the data was saved successful
     */
    bool save(const std::string &filename) const;
    
    /**
     Loads a vector from a CSV file. This assumes that the data has been saved as rows and columns in the CSV file
     and that there are an equal number of columns per row.
     
     This replaces the deprecated loadFromCSVFile function.
     
     @param filename: the name of the CSV file
     @return returns true or false, indicating if the data was loaded successful
     */
    bool load(const std::string &filename,const char seperator = ',');
    
    /**
     Prints the VectorFloat contents to std::cout
     
     @param title: sets the title of the data that will be printed to std::cout
     @return returns true or false, indicating if the print was successful
     */
    bool print(const std::string title="") const;
    
    /**
     Scales the vector to a new range given by the min and max targets, this uses the minimum and maximum values in the 
     existing vector as the minSource and maxSource for min-max scaling.
     
     @return returns true if the vector was scaled, false otherwise
     */
    bool scale(const float_t minTarget,const float_t maxTarget,const bool constrain);
    
    /**
     Scales the vector to a new range given by the min and max targets using the ranges as the source ranges.
     
     @return returns true if the vector was scaled, false otherwise
     */
    bool scale(const float_t minSource,const float_t maxSource,const float_t minTarget,const float_t maxTarget,const bool constrain);

    float_t getMinValue() const;

    float_t getMaxValue() const;
    
    float_t getMean() const;
    
    float_t getStdDev() const;
    
    MinMax getMinMax() const;
    
protected:
  
    WarningLog warningLog;
    ErrorLog errorLog;
    
};
    
GRT_END_NAMESPACE

#endif //Header guard
