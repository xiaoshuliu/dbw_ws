//#line 2 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
// 
// File autogenerated for the dbw_mkz_twist_controller package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

#ifndef __dbw_mkz_twist_controller__TWISTTESTCONFIG_H__
#define __dbw_mkz_twist_controller__TWISTTESTCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace dbw_mkz_twist_controller
{
  class TwistTestConfigStatics;
  
  class TwistTestConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(TwistTestConfig &config, const TwistTestConfig &max, const TwistTestConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const TwistTestConfig &config1, const TwistTestConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, TwistTestConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const TwistTestConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, TwistTestConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const TwistTestConfig &config) const = 0;
      virtual void getValue(const TwistTestConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level, 
          std::string a_description, std::string a_edit_method, T TwistTestConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T (TwistTestConfig::* field);

      virtual void clamp(TwistTestConfig &config, const TwistTestConfig &max, const TwistTestConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const TwistTestConfig &config1, const TwistTestConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, TwistTestConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const TwistTestConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, TwistTestConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const TwistTestConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const TwistTestConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, TwistTestConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, TwistTestConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<TwistTestConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(TwistTestConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("publish"==(*_i)->name){publish = boost::any_cast<bool>(val);}
        if("speed_units"==(*_i)->name){speed_units = boost::any_cast<int>(val);}
        if("speed"==(*_i)->name){speed = boost::any_cast<double>(val);}
        if("yaw_method"==(*_i)->name){yaw_method = boost::any_cast<int>(val);}
        if("yaw_rate"==(*_i)->name){yaw_rate = boost::any_cast<double>(val);}
        if("yaw_radius"==(*_i)->name){yaw_radius = boost::any_cast<double>(val);}
        if("use_limits"==(*_i)->name){use_limits = boost::any_cast<bool>(val);}
        if("decel_max"==(*_i)->name){decel_max = boost::any_cast<double>(val);}
        if("accel_max"==(*_i)->name){accel_max = boost::any_cast<double>(val);}
      }
    }

    bool publish;
int speed_units;
double speed;
int yaw_method;
double yaw_rate;
double yaw_radius;
bool use_limits;
double decel_max;
double accel_max;

    bool state;
    std::string name;

    
}groups;



//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool publish;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int speed_units;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double speed;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int yaw_method;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double yaw_rate;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double yaw_radius;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool use_limits;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double decel_max;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double accel_max;
//#line 218 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("TwistTestConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const TwistTestConfig &__max__ = __getMax__();
      const TwistTestConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const TwistTestConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const TwistTestConfig &__getDefault__();
    static const TwistTestConfig &__getMax__();
    static const TwistTestConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const TwistTestConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void TwistTestConfig::ParamDescription<std::string>::clamp(TwistTestConfig &config, const TwistTestConfig &max, const TwistTestConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class TwistTestConfigStatics
  {
    friend class TwistTestConfig;
    
    TwistTestConfigStatics()
    {
TwistTestConfig::GroupDescription<TwistTestConfig::DEFAULT, TwistTestConfig> Default("Default", "", 0, 0, true, &TwistTestConfig::groups);
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.publish = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.publish = 1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.publish = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<bool>("publish", "bool", 0, "Publish twist command", "", &TwistTestConfig::publish)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<bool>("publish", "bool", 0, "Publish twist command", "", &TwistTestConfig::publish)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.speed_units = -2147483648;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.speed_units = 2147483647;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.speed_units = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<int>("speed_units", "int", 0, "Speed units (mps/mph/kph)", "{'enum_description': 'Speed units enumeration', 'enum': [{'srcline': 9, 'description': '', 'srcfile': '/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'SPEED_MPS'}, {'srcline': 10, 'description': '', 'srcfile': '/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'SPEED_MPH'}, {'srcline': 11, 'description': '', 'srcfile': '/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'SPEED_KPH'}]}", &TwistTestConfig::speed_units)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<int>("speed_units", "int", 0, "Speed units (mps/mph/kph)", "{'enum_description': 'Speed units enumeration', 'enum': [{'srcline': 9, 'description': '', 'srcfile': '/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'SPEED_MPS'}, {'srcline': 10, 'description': '', 'srcfile': '/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'SPEED_MPH'}, {'srcline': 11, 'description': '', 'srcfile': '/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'SPEED_KPH'}]}", &TwistTestConfig::speed_units)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.speed = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.speed = 150.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.speed = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<double>("speed", "double", 0, "Target speed (variable units)", "", &TwistTestConfig::speed)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<double>("speed", "double", 0, "Target speed (variable units)", "", &TwistTestConfig::speed)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.yaw_method = -2147483648;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.yaw_method = 2147483647;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.yaw_method = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<int>("yaw_method", "int", 0, "Yaw method (yaw_rate or radius)", "{'enum_description': 'Yaw method enumeration', 'enum': [{'srcline': 13, 'description': '', 'srcfile': '/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'YAW_RATE'}, {'srcline': 14, 'description': '', 'srcfile': '/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'YAW_RADIUS'}]}", &TwistTestConfig::yaw_method)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<int>("yaw_method", "int", 0, "Yaw method (yaw_rate or radius)", "{'enum_description': 'Yaw method enumeration', 'enum': [{'srcline': 13, 'description': '', 'srcfile': '/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'YAW_RATE'}, {'srcline': 14, 'description': '', 'srcfile': '/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'YAW_RADIUS'}]}", &TwistTestConfig::yaw_method)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.yaw_rate = -3.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.yaw_rate = 3.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.yaw_rate = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<double>("yaw_rate", "double", 0, "Target yaw rate (rad/s)", "", &TwistTestConfig::yaw_rate)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<double>("yaw_rate", "double", 0, "Target yaw rate (rad/s)", "", &TwistTestConfig::yaw_rate)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.yaw_radius = -1000000000.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.yaw_radius = 1000000000.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.yaw_radius = 1000000000.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<double>("yaw_radius", "double", 0, "Target radius (1/m)", "", &TwistTestConfig::yaw_radius)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<double>("yaw_radius", "double", 0, "Target radius (1/m)", "", &TwistTestConfig::yaw_radius)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.use_limits = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.use_limits = 1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.use_limits = 1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<bool>("use_limits", "bool", 0, "Use limits", "", &TwistTestConfig::use_limits)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<bool>("use_limits", "bool", 0, "Use limits", "", &TwistTestConfig::use_limits)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.decel_max = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.decel_max = 8.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.decel_max = 3.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<double>("decel_max", "double", 0, "Deceleration limit (m/s^2)", "", &TwistTestConfig::decel_max)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<double>("decel_max", "double", 0, "Deceleration limit (m/s^2)", "", &TwistTestConfig::decel_max)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.accel_max = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.accel_max = 8.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.accel_max = 3.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<double>("accel_max", "double", 0, "Acceleration limit (m/s^2)", "", &TwistTestConfig::accel_max)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TwistTestConfig::AbstractParamDescriptionConstPtr(new TwistTestConfig::ParamDescription<double>("accel_max", "double", 0, "Acceleration limit (m/s^2)", "", &TwistTestConfig::accel_max)));
//#line 246 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(TwistTestConfig::AbstractGroupDescriptionConstPtr(new TwistTestConfig::GroupDescription<TwistTestConfig::DEFAULT, TwistTestConfig>(Default)));
//#line 356 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<TwistTestConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<TwistTestConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<TwistTestConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    TwistTestConfig __max__;
    TwistTestConfig __min__;
    TwistTestConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const TwistTestConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static TwistTestConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &TwistTestConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const TwistTestConfig &TwistTestConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const TwistTestConfig &TwistTestConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const TwistTestConfig &TwistTestConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<TwistTestConfig::AbstractParamDescriptionConstPtr> &TwistTestConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<TwistTestConfig::AbstractGroupDescriptionConstPtr> &TwistTestConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const TwistTestConfigStatics *TwistTestConfig::__get_statics__()
  {
    const static TwistTestConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = TwistTestConfigStatics::get_instance();
    
    return statics;
  }

//#line 9 "/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg"
      const int TwistTest_SPEED_MPS = 0;
//#line 10 "/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg"
      const int TwistTest_SPEED_MPH = 1;
//#line 11 "/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg"
      const int TwistTest_SPEED_KPH = 2;
//#line 13 "/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg"
      const int TwistTest_YAW_RATE = 0;
//#line 14 "/home/liu/dbw_ws/src/dbw_mkz_ros/dbw_mkz_twist_controller/cfg/TwistTest.cfg"
      const int TwistTest_YAW_RADIUS = 1;
}

#endif // __TWISTTESTRECONFIGURATOR_H__
