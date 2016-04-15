//
//  LTHMonthYearPickerView.m
//  LTHMonthYearPickerView Demo
//
//  Created by Roland Leth on 30/11/13.
//  Copyright (c) 2014 Roland Leth. All rights reserved.
//

@class LTHMonthYearPickerView;

@protocol LTHMonthYearPickerViewDelegate <NSObject>
@optional
- (void)picker:(LTHMonthYearPickerView *)monthYearPickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component;
- (void)picker:(LTHMonthYearPickerView *)monthYearPickerView didSelectMonth:(NSString *)month;
- (void)picker:(LTHMonthYearPickerView *)monthYearPickerView didSelectYear:(NSString *)year;
- (void)picker:(LTHMonthYearPickerView *)monthYearPickerView didSelectMonth:(NSString *)month andYear:(NSString *)year;
- (void)picker:(LTHMonthYearPickerView *)monthYearPickerView didPressDoneWithMonth:(NSString *)month andYear:(NSString *)year;
- (void)pickerDidPressCancel:(LTHMonthYearPickerView *)monthYearPickerView;
/**
 @brief				  If you want to change your text field (and/or variables) dynamically by implementing any of the pickerDidSelect__ delegate methods, instead of doing the change when Done was pressed, you should implement this method too, so the Cancel button restores old values.
 @param initialValues @{ "month" : month, @"year" : year }
 */
- (void)picker:(LTHMonthYearPickerView *)monthYearPickerView didPressCancelWithInitialValues:(NSDictionary *)initialValues;
@end

@interface LTHMonthYearPickerView : UIView <UIPickerViewDataSource, UIPickerViewDelegate>

@property (nonatomic, weak) id<LTHMonthYearPickerViewDelegate> delegate;
@property (nonatomic, strong) UIPickerView *datePicker;
@property (nonatomic, strong) NSString *year;
@property (nonatomic, strong) NSString *month;


/**
 @brief				   Month / Year picker view, for those pesky Credit Card expiration dates and alike.
 @param date           set if you want the picker to be initialized with a specific month and year, otherwise it will be initialized with the current month and year.
 @param shortMonths    set to YES if you want months to be returned as Jan, Feb, etc, set to NO if you want months to be returned as January, February, etc.
 @param numberedMonths set to YES if you want months to be returned as 01, 02, etc. This takes precedence over shortMonths if set to YES.
 @param showToolbar    set to YES if you want the picker to have a Cancel/Done toolbar.
 @return a container view which contains the UIPicker and toolbar
 */
- (id)initWithDate:(NSDate *)date shortMonths:(BOOL)shortMonths numberedMonths:(BOOL)numberedMonths andToolbar:(BOOL)showToolbar;

/**
 @brief				   Month / Year picker view, for those pesky Credit Card expiration dates and alike.
 @param date           set if you want the picker to be initialized with a specific month and year, otherwise it will be initialized with the current month and year.
 @param shortMonths    set to YES if you want months to be returned as Jan, Feb, etc, set to NO if you want months to be returned as January, February, etc.
 @param numberedMonths set to YES if you want months to be returned as 01, 02, etc. This takes precedence over shortMonths if set to YES.
 @param showToolbar    set to YES if you want the picker to have a Cancel/Done toolbar.
 @param minYear        set value for minimum year that is displayed in picker.
 @param maxYear        set value for maximum year that is displayed in picker.
 @return a container view which contains the UIPicker and toolbar
 */
- (id)initWithDate:(NSDate *)date
			 shortMonths:(BOOL)shortMonths
		numberedMonths:(BOOL)numberedMonths
				andToolbar:(BOOL)showToolbar
					 minYear:(NSInteger)minYear
				andMaxYear:(NSInteger)maxYear;


/**
 @brief				   Month / Year picker view, for those pesky Credit Card expiration dates and alike.
 @param date           set if you want the picker to be initialized with a specific month and year, otherwise it will be initialized with the current month and year.
 @param shortMonths    set to YES if you want months to be returned as Jan, Feb, etc, set to NO if you want months to be returned as January, February, etc.
 @param numberedMonths set to YES if you want months to be returned as 01, 02, etc. This takes precedence over shortMonths if set to YES.
 @param showToolbar    set to YES if you want the picker to have a Cancel/Done toolbar.
 @param minDate        set value for minimum date that is displayed in picker. Day 1 is default.
 @param maxDate        set value for maximum date that is displayed in picker. Day 1 is default.
 @return a container view which contains the UIPicker and toolbar
 */
- (id)initWithDate:(NSDate *)date
			 shortMonths:(BOOL)shortMonths
		numberedMonths:(BOOL)numberedMonths
				andToolbar:(BOOL)showToolbar
					 minDate:(NSDate *)minDate
				andMaxDate:(NSDate *)maxDate;
@end