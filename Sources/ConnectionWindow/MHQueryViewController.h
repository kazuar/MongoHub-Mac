//
//  MHQueryViewController.h
//  MongoHub
//
//  Created by Syd on 10-4-28.
//  Copyright 2010 ThePeppersStudio.COM. All rights reserved.
//

#import "MHTabItemViewController.h"
#import "UKSyntaxColoredTextViewController.h"

@class MHResultsOutlineViewController;
@class MODCollection;
@class MHConnectionStore;
@class MHIndexEditorController;

@interface MHQueryViewController : MHTabItemViewController
{
    MODCollection                               *_collection;
    MHConnectionStore                           *_connectionStore;
    NSMutableDictionary                         *_jsonWindowControllers;
    
    NSTabView                                   *_tabView;
    NSSegmentedControl                          *_segmentedControl;
    
    MHResultsOutlineViewController              *_findResultsViewController;
    NSOutlineView                               *_findResultsOutlineView;
    NSComboBox                                  *_findCriteriaComboBox;
    NSTextField                                 *_findFieldFilterTextField;
    NSTextField                                 *_findSkipTextField;
    NSTextField                                 *_findLimitTextField;
    NSTextField                                 *_findSortTextField;
    NSTextField                                 *_findTotalResultsTextField;
    NSTextField                                 *_findQueryTextField;
    NSProgressIndicator                         *_findQueryLoaderIndicator;
    NSButton                                    *_findRemoveButton;
    NSPopUpButton                               *_findExpandPopUpButton;
    NSButton                                    *_findNextResultButton;
    NSButton                                    *_findPreviousResultButton;
    
    IBOutlet NSButton                           *_insertButton;
    IBOutlet NSTextView                         *_insertDataTextView;
    IBOutlet NSTextField                        *_insertResultsTextField;
    IBOutlet NSProgressIndicator                *_insertLoaderIndicator;
    UKSyntaxColoredTextViewController           *_syntaxColoringController;
    
    NSView                                      *_updateTabView;
    NSButton                                    *_updateButton;
    NSTextField                                 *_updateCriteriaTextField;
    NSButton                                    *_updateUpsetCheckBox;
    NSButton                                    *_updateMultiCheckBox;
    NSTextField                                 *_updateResultsTextField;
    NSTextField                                 *_updateQueryTextField;
    NSProgressIndicator                         *_updateQueryLoaderIndicator;
    NSMutableArray                              *_updateOperatorViews;
    NSArray                                     *_updateOperatorList;
    
    IBOutlet NSButton                           *_removeButton;
    IBOutlet NSTextField                        *_removeCriteriaTextField;
    IBOutlet NSTextField                        *_removeResultsTextField;
    IBOutlet NSTextField                        *_removeQueryTextField;
    IBOutlet NSProgressIndicator                *_removeQueryLoaderIndicator;
    
    NSOutlineView                               *_indexOutlineView;
    NSProgressIndicator                         *_indexLoaderIndicator;
    NSButton                                    *_indexDropButton;
    NSButton                                    *_indexCreateButton;
    MHResultsOutlineViewController              *_indexesOutlineViewController;
    MHIndexEditorController                     *_indexEditorController;
    
    IBOutlet NSTextView                         *_mrMapFunctionTextView;
    IBOutlet NSTextView                         *_mrReduceFunctionTextView;
    IBOutlet NSTextField                        *_mrCriteriaTextField;
    IBOutlet NSTextField                        *_mrOutputTextField;
    IBOutlet NSProgressIndicator                *_mrLoaderIndicator;
    MHResultsOutlineViewController              *_mrOutlineViewController;
    IBOutlet NSOutlineView                      *_mrOutlineView;
    
    IBOutlet id                                 _monTest;
}

@property (nonatomic, readonly, strong) MODCollection *collection;
@property (nonatomic, readonly, strong) MHConnectionStore *connectionStore;

- (instancetype)initWithCollection:(MODCollection *)collection connectionStore:(MHConnectionStore *)connectionStore;

- (IBAction)segmentedControlAction:(id)sender;

- (void)showEditWindow:(id)sender;
- (void)jsonWindowWillClose:(id)sender;
@end

@interface MHQueryViewController (InsertTab)
- (IBAction)insertQuery:(id)sender;

@end

@interface MHQueryViewController (RemoveTab)
- (IBAction)removeQuery:(id)sender;
- (void)removeQueryComposer:(id)sender;

@end

@interface MHQueryViewController (mrTab)
- (IBAction)mapReduce:(id)sender;

@end

@interface MHQueryViewController (UKSyntaxColoredTextViewDelegate) <UKSyntaxColoredTextViewDelegate>
@end
