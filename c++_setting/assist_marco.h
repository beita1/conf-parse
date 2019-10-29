#define DEFINE_PROPERTY(type, name)			\
private:									\
	type m_##name;							\
public:										\
void name(const type v)						\
{											\
	m_##name = v;							\
}											\
type name()	const							\
{											\
	return m_##name;						\
}											\

#define DEFINE_PROPERTY_REF(type, name)		\
private:									\
	type m_##name;							\
public:										\
void name(const type& v)					\
{											\
	m_##name = v;							\
}											\
const type& name() const					\
{											\
	return m_##name;						\
}											\
type& name()								\
{											\
	return m_##name;						\
}											\

#define DEFINE_PROPERTY_READONLY(type, name)	\
protected:										\
	type m_##name;								\
public:											\
type name()	const								\
{												\
	return m_##name;							\
}	

#define DEFINE_PROPERTY_REF_READONLY(type, name)		\
protected:												\
	type m_##name;										\
public:													\
const type& name() const								\
{														\
	return m_##name;									\
}														\
type& name()											\
{														\
	return m_##name;									\
}	
