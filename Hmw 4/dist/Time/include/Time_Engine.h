#ifndef ENGINE_TIME_H
#define ENGINE_TIME_H

enum Duration
{
	/* For constructing a Time of zero. */
	TIME_ZERO,

	/* For constructing one NTSC 60 hz frame of Time. */
	TIME_NTSC_FRAME,

	/* For constructing one NTSC 60 hz frame of Time. */
	TIME_NTSC_30_FRAME,

	/* For constructing one PAL 50 hz frame of Time. */
	TIME_PAL_FRAME,

	/* For constructing one millisecond of Time. */
	TIME_ONE_MILLISECOND,

	/* For constructing one second of Time. */
	TIME_ONE_SECOND,

	/* For constructing one minute of Time. */
	TIME_ONE_MINUTE,

	/* For constructing one hour of Time. */
	TIME_ONE_HOUR,

	/*
	* For constructing the most <i>negative</i> Time
	* that can be represented.
	*/
	TIME_MIN,

	/*
	* For constructing the most positive Time
	* that can be represented.
	*/
	TIME_MAX,

	// insure the enum is size int
	TIME_DWORD = 0x7FFFFFFF
};


//---------------------------------------------------------------------------
// CLASS DECLARATION:
//---------------------------------------------------------------------------

class Time_Engine
{

public:

	//-----------------------------------------------------------------
	// Friends
	//-----------------------------------------------------------------

	/*
	* return: The product of the specified float and Time.
	*
	* Example:
	*    const Time halfSecond = 0.5f * Time(ONE_SECOND);
	*/
	friend const Time_Engine operator*(const float, const Time_Engine &);

	/*
	* return: The product of the specified integer and Time.
	*
	* Example:
	*    const Time fourMinutes = 4 * Time(ONE_MINUTE);
	*/
	friend const Time_Engine operator*(const int, const Time_Engine &);

	//-----------------------------------------------------------------
	// Constructors / Destructors / Assignment
	//-----------------------------------------------------------------

	/* Creates a Time equal to Time(ZERO). */
	inline Time_Engine();

	/*
	* Creates the specific amount of Time.
	*
	* Example:
	*    const Time oneSecond( ONE_SECOND );
	*/
	explicit Time_Engine(const Duration);

	/* Creates a copy of the specified Time. */
	inline Time_Engine(const Time_Engine&);

	/*
	* Assigns the right-hand side to this Time.
	* return: this Time.
	*
	*  Example:
	*    const Time tickDuration = Time(NTSC_DURATION);
	*/
	inline Time_Engine& operator=(const Time_Engine& rhs);

	// destrutor
	~Time_Engine()
	{ }

	//-----------------------------------------------------------------
	// Comparisons
	//-----------------------------------------------------------------

	/*
	* return: true if this Time is equal to the right-hand side.
	*
	*  Example:
	*    assert( Time(ONE_HOUR)   == 60 * Time(ONE_MINUTE) );
	*    assert( Time(ONE_MINUTE) == 60 * Time(ONE_SECOND) );
	*/
	bool operator==(const Time_Engine& rhs) const;

	/*
	* return: true if this Time is not equal to the right-hand side.
	*/
	bool operator!=(const Time_Engine& rhs) const;

	/*
	* return: true if this Time is less than the right-hand side.
	*
	* Example:
	*    bool couldBeOttosMileTime( const Time t )
	*    {
	*       return( t < 4 * Time(ONE_MINUTE) );
	*    }
	*/
	bool operator<(const Time_Engine& rhs) const;

	/*
	* return: true if this Time is less or equal to the right-hand side.
	*/
	bool operator<=(const Time_Engine& rhs) const;

	/*
	* return: true if this Time is greater than the right-hand side.
	*/
	bool operator>(const Time_Engine& rhs) const;

	/*
	* return: true if this Time is greather than or equal to
	*  the right-hand side.
	*/
	bool operator>=(const Time_Engine& rhs) const;

	//-----------------------------------------------------------------
	// Negation / Addition / Subtraction
	//-----------------------------------------------------------------

	/*
	* return: A negative copy of this Time.
	*
	* Example:
	*    void neverFail( const Time t )
	*    {
	*       assert( t + (-t) == Time(ZERO) );
	*    }
	*/
	const Time_Engine operator-() const;

	/*
	* return: The sum of this Time and the right-hand side.
	*
	* Example:
	*    void neverFail( const Time t )
	*    {
	*       assert( t + t == 2 * t );
	*    }
	*/
	const Time_Engine operator+(const Time_Engine& rhs) const;

	/*
	* return: The difference between this Time and the right-hand side.
	*
	* Example:
	*    void neverFail( const Time t )
	*    {
	*       assert( t - t == Time(ZERO) );
	*    }
	*/
	const Time_Engine operator-(const Time_Engine& rhs) const;

	/*
	* Adds the right-hand side to this Time.
	*
	* return: This Time.
	*
	*  Example:
	*    void zeroOutTime( Time& t )
	*    {
	*       t += (-t);
	*       assert( Time(ZERO) == t );
	*    }
	*/
	Time_Engine& operator+=(const Time_Engine& rhs);

	/*
	* Subtracts the right-hand side from this Time_Engine.
	*
	* return: This Time_Engine.
	*
	*  Example:
	*    void zeroOutTime_Engine( Time_Engine& t )
	*    {
	*       t -= t;
	*       assert( Time_Engine(ZERO) == t );
	*    }
	*/
	Time_Engine& operator-=(const Time_Engine& rhs);

	//-----------------------------------------------------------------
	// Multiplication
	//-----------------------------------------------------------------

	/*
	* return: The product of this Time_Engine and the specified float.
	*
	* Example:
	*    const Time_Engine halfSecond = Time_Engine(ONE_SECOND) * 0.5f;
	*/
	const Time_Engine operator*(const float) const;

	/*
	* return: The product of this Time_Engine and the specified integer.
	*
	*  Example:
	*    const Time_Engine fourMinutes = Time_Engine(ONE_MINUTE) * 4;
	*/
	const Time_Engine operator*(const int) const;

	/*
	* Multiplies this Time_Engine by the specified float.
	*
	* return: This Time_Engine.
	*
	* Example:
	*    void decayTime_Engine( Time_Engine& t )
	*    {
	*       t *= 0.95f;
	*    }
	*/
	Time_Engine& operator*=(const float);

	/*
	* Multiplies this Time_Engine by the specified integer.
	*
	* return: This Time_Engine.
	*
	* Example:
	*    void doubleTime_Engine( Time_Engine& t )
	*    {
	*       t *= 2;
	*    }
	*/
	Time_Engine& operator*=(const int);

	//-----------------------------------------------------------------
	// name: Division
	//-----------------------------------------------------------------

	/*
	* return: The ratio of this Time_Engine divided by the denominator Time_Engine.
	*
	* note: Dividing by Time_Engine::ZERO is undefined.
	*/
	float operator/(const Time_Engine& denominator) const;

	/*
	* return: The result of dividing this Time_Engine and by the
	* specified float.
	*
	* note: Dividing by zero is undefined.
	*/
	const Time_Engine operator/(const float denominator) const;

	/*
	* return: The result of dividing this Time_Engine and by the
	* specified integer.
	*
	* note: Dividing by zero is undefined.
	*/
	const Time_Engine operator/(const int denominator) const;

	/*
	* Divides this Time_Engine by the specified float.
	*
	* return: This Time_Engine.
	*
	* note: Dividing by zero is undefined.
	*/
	Time_Engine& operator/=(const float);

	/*
	* Divides this Time_Engine by the specified integer.
	*
	* return: This Time_Engine.
	*
	* note: Dividing by zero is undefined.
	*/
	Time_Engine& operator/=(const int);

	//-----------------------------------------------------------------
	// Quotient / Remainder
	//-----------------------------------------------------------------

	/*
	* return: The <i>truncated</i>, integral division of the
	* numerator and denominator.  In other words,
	* the result of the division is rounded down to the nearest
	* integer.
	*
	* note: Dividing by Time_Engine(ZERO) is undefined.
	*/
	static int 	quotient(const Time_Engine& numerator, const Time_Engine& denominator);

	static float quotientFloat(const Time_Engine& numerator, const Time_Engine& denominator);
	/*
	* return: The remainder of dividing the numerator into the
	* denominator.  This is the equivalent of a modulus operation.
	*
	* note: Dividing by Time_Engine(ZERO) is undefined.
	*/
	static const Time_Engine 	remainder(const Time_Engine& numerator, const Time_Engine& denominator);

private:
	// types
	typedef int Representation;

	// constructor
	explicit Time_Engine(const Representation);

	// data
	Representation _rawTime;
};




//---------------------------------------------------------------------------
// INLINED IMPLEMENTATION:
//---------------------------------------------------------------------------
Time_Engine::Time_Engine() : _rawTime(0)
{
}


Time_Engine::Time_Engine(const Time_Engine& rhs) : _rawTime(rhs._rawTime)
{
}


Time_Engine& Time_Engine::operator=(const Time_Engine& rhs)
{
	if (this != &rhs)
	{
		this->_rawTime = rhs._rawTime;
	}

	return(*this);
}



#endif  

